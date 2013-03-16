#!/bin/bash
HOME_PATH=/home/gabriel
OPENWRT_PATH=$HOME_PATH/Documents/INSA_2011_-/4IR_B1_S2/Ptut/openwrt-milkymist
LINUX_MILKY_PATH=$HOME_PATH/Documents/INSA_2011_-/4IR_B1_S2/Ptut/linux-milkymist

echo "Source startise"
source startise 2>&1 > /dev/null 
echo "Move to linux-milkymist"
cd $LINUX_MILKY_PATH
echo "Make proper"
#make mrproper > /dev/null 2>&1
echo "Make defconfig"
#ARCH=lm32 make defconfig > /dev/null 2>&1
echo "Make kernel"
#ARCH=lm32 CROSS_COMPILE=lm32-rtems4.11- make simpleImage.milkymist_one > /dev/null 2>&1
export QEMU_AUDIO_DRV=none
echo "Create filesystem"
cd $OPENWRT_PATH
#ARCH=lm32 CROSS_COMPILE=lm32-rtems4.11- make
echo "Launch qemu"
qemu-system-lm32  -M milkymist -kernel $LINUX_MILKY_PATH/arch/lm32/boot/simpleImage.milkymist_one -append "root=/dev/ram console=ttyS0 init=/bin/sh" -initrd $OPENWRT_PATH/bin/lm32/openwrt-lm32-root.bin -nographic
