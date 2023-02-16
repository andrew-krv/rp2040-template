cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(my_project)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(Sample main.cpp)

# pull in common dependencies
target_link_libraries(Sample pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(Sample)

