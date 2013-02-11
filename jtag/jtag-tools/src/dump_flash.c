//#######################################################################################################################
//
//		AUTHOR: Clément MICHAUD
//		DATE: February 11th, 2013
//		INSTITUTE: INSA Toulouse (France)
//
//		DESCRIPTION: This tool dumps several bytes of memory at the base address given as parameter.
//		PARAMTERS: 
//				OUTPUT_FILENAME: The name of the file where the dump will be written
//				BASE_ADDRESS: The starting address (0xHHHHHH)
//				SIZE_TO_DUMP: Number of 16b words to dump
//
//#######################################################################################################################


#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "flash_api.h"
#include "libfpgalink.h"
#include "utils.h"


u16 readFlash(struct FLContext *handle, u32 address){
	return readWord(handle, address);
}

int main(int argc, char **argv){

	struct FLContext *handle = NULL;
	char vp[] = "1443:0007";
	int i;
	int sizeToDump = 0;
	int returnError;
	u32 baseAddress;
	u32 currentAddress;

	if(argc != 4){
		printf("Usage: %s <output_file> <base_address> <16b_to_dump>\nBe careful the base address must be in hex of 24 bits max (0xHHHHHH)\n", argv[0]);
		exit(-1);
	}

	FILE *file = fopen(argv[1], "w");

	if(file == NULL){
		printf("The file cannot be open in write mode");
		exit(-1);
	}

	baseAddress = getHexFromString(argv[2], &returnError);
	sizeToDump = atoi(argv[3]);

	printf("Initialise device...\n");
	flInitialise();

	flOpen(vp, &handle, NULL);

	currentAddress = baseAddress;
	
	for(i=0; i<sizeToDump; i++){
		u16 data = readFlash(handle, currentAddress);
		u8 d1 = data & 0xFF;
		u8 d2 = (data & 0xFF00) >> 8;
		fputc(d1, file);
		fputc(d2, file);
		currentAddress++;
	}
	printf("Dump succeded\n");
	fclose(file);

	printf("Disconnecting device...\n");
	flClose(handle);

	return 0;
}
