#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

constexpr uint irq_pin = 5;
constexpr uint pwm_pin = 0;

static_assert(irq_pin != pwm_pin, "interrupt and pwm pins can not be the same");

enum channel_level_t : uint16_t
{
    full = UINT16_MAX,
    quater = full / 4,
    half = full / 2
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

    pwm_set_gpio_level(pwm_pin, level);
}

void init_gpio_irq() {
    constexpr auto irq_mask = GPIO_IRQ_EDGE_RISE|GPIO_IRQ_EDGE_FALL;
    gpio_set_irq_enabled_with_callback(irq_pin, irq_mask, true, &gpio_callback);
}

void init_pwm() {
    gpio_set_function(pwm_pin, GPIO_FUNC_PWM);
    pwm_set_gpio_level(pwm_pin, channel_level_t::quater);
}

int main() {
    printf("Hello, world!\n");
    return 0;
}