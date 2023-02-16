# rp2040-template
Template project for RP2040 controller

# SDK setup

## Linux specific

### Prerequisites

sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib

### Obtaining SDK

cd $HOME
mkdir rpi-sdk
git clone https://github.com/raspberrypi/pico-sdk.git && cd pico-sdk && git checkout 2ccab11

nano .bashrc
***Add line export PICO_SDK_PATH=$HOME/rpi-sdk/pico-sdk***
