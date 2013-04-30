#!/bin/bash
export LD_LIBRARY_PATH=libfpgalink-20120621/linux.x86_64/rel/
KERNEL="/Documents/INSA_2011_-/4IR_B1_S2/Ptut/linux-milkymist/arch/lm32/boot/simpleImage.milkymist_one"
INITRD="/Documents/INSA_2011_-/4IR_B1_S2/Ptut/openwrt-milkymist/bin/lm32/openwrt-lm32-root.ext4"
CMD="root=/dev/ram console=ttyS0 init=/bin/sh"

make fpga
make compile
clear
echo "Uploading kernel $KERNEL"
./build/upload_flash $KERNEL 0x460000
if [ $? -ne 0 ]
   echo "Error while uploading Kernel"
   exit

#echo "Uploading initrd $INITRD"
#echo "- initrd start address -"
#cat addr_to_upload
#echo ""
#./build/upload_flash $INITRD `cat addr_to_upload`
#if [ $? -ne 0 ]
#   echo "Error while uploading Kernel"
#   exit
   
#echo "- initrd end address + 1 -"  
#cat addr_to_upload
#echo ""  
#echo "Uploading command $CMD"
#./build/upload_flash $CMD `cat addr_to_upload`
#if [ $? -ne 0 ]
#   echo "Error while uploading Kernel"
 #  exit

