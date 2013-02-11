//########################################################################################################
//
//		AUTHOR: Clément MICHAUD
//		DATE: February 11th, 2013
//		INSTITUTE: INSA Toulouse (France)
//
//		DESCRIPTION: This API allows communication with the flash chip
//
//########################################################################################################


#include "flash_api.h"

//*****************************************************
// Puts the address on the address bus to the flash
// and puts data on the data bus
//*****************************************************
void writeCommand(struct FLContext *handle, u32 address, u16 data){
	u8 buffer[6];
	
	buffer[0] = WRITE;
	buffer[1] = address;
	buffer[2] = (address & 0xFF00) >> 8;
	buffer[3] = (address & 0xFF0000) >> 16;
        buffer[4] = data & 0xFF;
	buffer[5] = (data & 0xFF00) >> 8;

	//printf("Address %x-%x\n", (u8)buffer[2], (u8)buffer[1]);
        flWriteChannel(handle, 1000, 0, 6, buffer, NULL); 
}

//*****************************************************
// Puts the address on the address bus
// And gets the value from the data bus
// Then returns this value
//*****************************************************
u16 readCommand(struct FLContext *handle, u32 address){
	u8 buffer[4];
	
	buffer[0] = READ;
	buffer[1] = address & 0xFF;
	buffer[2] = (address & 0xFF00) >> 8;
	buffer[3] = (address & 0xFF0000) >> 16;
	// Ask the flash to send the data at the specified address
	flWriteChannel(handle, 1000, 0, 4, buffer, NULL);
	flReadChannel(handle, 1000, 0, 2, buffer, NULL); 
	u16 ret = buffer[0] | (buffer[1] << 8);
	return ret;
}

//***************************************************
// Unlock the block associated with the address
//***************************************************
void unlockBlock(struct FLContext *handle, u32 block){
	writeCommand(handle, block, 0x60);
	// Confirm the unlock.	
	writeCommand(handle, block, 0xD0);
}


//***********************************************************
// Write a word of 16 bits (data)  at the given address 
// Then returns the status code from the flash chip
//***********************************************************
u8 writeWord(struct FLContext *handle, u32 address, u16 data){
	// Enter in bit alterable mode	
	writeCommand(handle, address, 0x42);
	// Write data
	writeCommand(handle, address, data);
	
	// Get the status register
	u16 status=readCommand(handle, address);
	return status & 0xFF;
}


//***************************************************************
// Read a word of 16 bits from the flash at the given address
// Then returns this word
//***************************************************************
u16 readWord(struct FLContext *handle, u32 address){
	writeCommand(handle, address, 0xFF);
	u16 word = readCommand(handle, address);
	return word;
}



