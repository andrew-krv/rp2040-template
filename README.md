# rp2040-template
Template project for RP2040 controller simple interrupt handling which switches PWM

---

# Prerequisites

## Linux

```bash
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib build-essential
```

---

## MacOS

```bash
brew install cmake && brew install git && brew install gcc-arm-embedded
```

---

## Windows

Install [Arm GNU Toolchain](https://developer.arm.com/downloads/-/gnu-rm), CMake, Python3 and Visual Studio

---

# Obtaining SDK

## Unix

```bash
cd $HOME && mkdir rpi-sdk && cd rpi-sdk
git clone https://github.com/raspberrypi/pico-sdk.git && cd pico-sdk && git checkout 1.5.0 && git submodule update --init

nano .bashrc #Add line: export PICO_SDK_PATH=$HOME/rpi-sdk/pico-sdk
```

## Windows

Open destination folder where you whish to clone the SDK repository and clone with
following command:

```bash
git clone https://github.com/raspberrypi/pico-sdk.git && cd pico-sdk && git checkout 1.5.0 && git submodule update --init
```

Add SDK folder to system Environment variables

---

# Project setup

Simple configuration with either commandline CMake, GUI CMake or CMake extension
in Visual Studio Code. [Windows](https://len42.github.io/rp2040-dev-setup.html) setup guide is located here

---
