cmake_minimum_required(VERSION 3.13)
set (CMAKE_CXX_STANDARD 17)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(my_project)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(Sample src/main.cpp)

# pull in common dependencies
target_link_libraries(Sample pico_stdlib hardware_pwm)

# create map/bin/hex file etc.
pico_add_extra_outputs(Sample)

