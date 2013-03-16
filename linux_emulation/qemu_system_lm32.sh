#!/bin/bash
echo "Install libsdl-dev"
aptitude install libsdl-dev
echo "Clone qemu git"
git clone git://git.qemu.org/qemu.git
echo "Move to folder"
cd qemu
echo "Configure"
./configure --target-list="lm32-softmmu" --enable-sdl 2>&1 > /dev/null
echo "Make"
make 2>&1 > /dev/null
echo "Make install"
make install 2>&1 > /dev/null
