cd /Documents/INSA_2011_-/4IR_B1_S2/Ptut/insasheep/jtag/jtag-tools
export LD_LIBRARY_PATH=libfpgalink-20120621/linux.x86_64/rel/
make
make fpga
make compile
./build/upload_flash /Documents/INSA_2011_-/4IR_B1_S2/Ptut/insasheep/milkymist-various/software/bios/bios.bin 0x430000 

