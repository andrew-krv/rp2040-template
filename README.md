# rp2040-template
Template project for RP2040 controller
---

# SDK setup

# Unix

## Prerequisites

### Linux

```bash
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib build-essential
```
---

### MacOS

```bash
brew install cmake && brew install git && brew install gcc-arm-embedded
```
---

## Obtaining SDK

```bash
cd $HOME
mkdir rpi-sdk && cd rpi-sdk
git clone https://github.com/raspberrypi/pico-sdk.git && cd pico-sdk && git checkout 1.5.0 && git submodule update --init

nano .bashrc #Add line export PICO_SDK_PATH=$HOME/rpi-sdk/pico-sdk***
```
---