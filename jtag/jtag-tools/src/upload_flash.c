//#######################################################################################################################
//
//		AUTHOR: Clément MICHAUD
//		DATE: February 11th, 2013
//		INSTITUTE: INSA Toulouse (France)
//
//		DESCRIPTION: This tool programs the flash with a bin file at the base address given as parameter.
//		PARAMTERS: 
//				INPUT_FILENAME: The name of the file to write in the flash
//				BASE_ADDRESS: The starting address (0xHHHHHH)
//
//#######################################################################################################################


#include <stdio.h>
#include <stdlib.h>

#include "libfpgalink.h"
#include <string.h>

#include "flash_api.h"
#include "utils.h"


void writeFlash(struct FLContext *handle, u32 address, u16 data){
	u8 status = writeWord(handle, address, data);
	printf("STATUS: %x\n", status); 
}
 

u16 readFlash(struct FLContext *handle, u32 address){
	return readWord(handle, address);
}

int main(int argc, char **argv){

	struct FLContext *handle = NULL;
	char vp[] = "1443:0007";
	char c = 1;
	int cpt;
	int oddByte = 0;
	char temp[2]; 
	u16 word;
	u32 currentAddress = 0x00;
	u32 baseAddress = 0x00;
	u32 totalSize;
	int error = 0;
	int i;
	int returnError;
	u8 status;
   FILE * addFile;
   
   addFile = fopen("addr_to_upload", "w+");

	if(argc != 3){
		printf("Usage: %s <input_file> <base_address>\n", argv[0]);
		exit(-1);
	}

	FILE *file = fopen(argv[1], "rb");

	if(file == NULL){
		printf("The file cannot be open in readonly mode");
		exit(-1);
	}

   
	printf("Initialise device...\n");
	flInitialise();

	flOpen(vp, &handle, NULL);

	// Get the hex base address
	baseAddress = getHexFromString(argv[2], &returnError);

	currentAddress = baseAddress;
	cpt = 0;
	
    fseek(file, 0L, SEEK_END); // seek to end of file
    totalSize = ftell(file); // get current file pointer
    fseek(file, 0L, SEEK_SET);
   
	printf("Write data at 0x%x of size 0x%x (%d bytes)\n", currentAddress,totalSize, totalSize);

	while(!feof(file) && error == 0){
		c = fgetc(file);
		temp[oddByte] = c;
		oddByte = (oddByte + 1) % 2;
		if(oddByte == 0){
			word = (temp[1] & 0xFF) | ((temp[0] & 0xFF) << 8);
			if((currentAddress & 0xFFFF) == 0) {
				unlockBlock(handle, currentAddress);
			}
			status = writeWord(handle, currentAddress, word);
			if(status != 0x80){
				error = 1;
			}

			printf("%d%%\r", 100*cpt/totalSize);
		    fflush(stdout);
			currentAddress++;
			cpt += 2;
		}
	} 

	fclose(file);
	if(!error)
		printf("Upload succeded\n");
	else{
		printf("Error uploading the file\n");
		printf("Error at 0x%x with %x\n", --currentAddress, status);
		flClose(handle);
		fclose(addFile);
		exit(-1);
	}
	


	flLoadStandardFirmware(vp, vp, "D0234", NULL);
	printf("Disconnecting device...\n");
	flClose(handle);
	if(addFile == NULL)
	{
	   perror("Error: creating addFile");
	}
	else
	{
      fprintf(addFile, "%d",currentAddress);
      fclose(addFile);
   }
	return 0;
}
