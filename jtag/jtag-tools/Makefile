
PLATFORM=linux.x86_64

FPGA_DIR=libfpgalink-20120621
CC=gcc

XSVF=~/Xilinx_projects/program_flash/program.xsvf

LIB_DIR=$(FPGA_DIR)/$(PLATFORM)/rel
LIB_OPTIONS=-L$(LIB_DIR) -Wl,--gc-sections,-rpath,\$ORIGIN,-rpath-link,$(LIB_DIR) -lfpgalink

OBJ_FILES=upload_flash flash_api

install:
	tar xzf libfpgalink-20120621.tar.gz

fpga:
	$(LIB_DIR)/flcli -v 1443:0007 -i 1443:0007 -s -x $(XSVF) 

compile: dump_flash.o upload_flash.o flash_api.o utils.o
	$(CC) -o build/dump_flash $(LIB_OPTIONS) obj/dump_flash.o obj/utils.o obj/flash_api.o
	$(CC) -o build/upload_flash $(LIB_OPTIONS) obj/upload_flash.o obj/utils.o obj/flash_api.o

%.o: src/%.c
	$(CC) -I$(FPGA_DIR)/ $(LIB_OPTIONS) -o obj/$@ -c $^ -L$(LIB_DIR)

clean:
	rm -R $(FPGA_DIR) obj/*.o build/dump_flash build/upload_flash	
