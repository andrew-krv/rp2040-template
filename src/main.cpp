#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/irq.h"

/***********************************PINS***************************************/

constexpr uint irq_pin = 5;

constexpr uint pwm_pin =
#ifndef PICO_DEFAULT_LED_PIN
    0;
#warning pwm/led_fade example requires a board with a regular LED falling back to pin 0
#else
    PICO_DEFAULT_LED_PIN;
#endif

static_assert(irq_pin != pwm_pin, "interrupt and pwm pins can not be the same");

/***********************************PINS***************************************/


/***********************************GPIO***************************************/

// One byte values instead of two in order to make change faster and linear
enum channel_level_t : uint16_t
{
    none = 0,
    full = 255,
    half = 127,
    quater = 65
};
static auto level = channel_level_t::quater;

void gpio_callback(uint gpio, uint32_t events) {
    switch (level)
    {
    case channel_level_t::quater:
        level = channel_level_t::half;
        break;
    case channel_level_t::half:
        level = channel_level_t::full;
        break;
    case channel_level_t::full:
    default:
        level = channel_level_t::quater;
        break;
    }
}

void init_gpio_irq() {
    constexpr auto irq_mask = GPIO_IRQ_EDGE_RISE|GPIO_IRQ_EDGE_FALL;
    gpio_set_irq_enabled_with_callback(irq_pin, irq_mask, true, &gpio_callback);
}

/***********************************GPIO***************************************/


/***********************************PWM****************************************/

void on_pwm_wrap() {
    static int fade = 0;
    if (fade == level) {
        return;
    }

    fade += (level > fade) ? 1 : -1;

    pwm_clear_irq(pwm_gpio_to_slice_num(pwm_pin));
    pwm_set_gpio_level(pwm_pin, fade * fade);
}

void init_pwm() {
    gpio_set_function(pwm_pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pwm_pin);

    pwm_clear_irq(slice_num);
    pwm_set_irq_enabled(slice_num, true);
    irq_set_exclusive_handler(PWM_IRQ_WRAP, on_pwm_wrap);
    irq_set_enabled(PWM_IRQ_WRAP, true);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.f);
    pwm_init(slice_num, &config, true);
}


/***********************************PWM****************************************/

int main() {
    init_pwm();
    init_gpio_irq();

    while (1)
        tight_loop_contents();
}
