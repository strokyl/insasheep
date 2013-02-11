
#ifndef _FLASH_API_H
#define _FLASH_API_H

#define WRITE 1
#define READ 0
#define STOP_PROCESS 2

#include "libfpgalink.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


void writeCommand(struct FLContext *handle, u32 address, u16 data);
u16 readCommand(struct FLContext *handle, u32 address);
void unlockBlock(struct FLContext *handle, u32 block);


u8 writeWord(struct FLContext *handle, u32 address, u16 data);
u16 readWord(struct FLContext *handle, u32 address);

#endif

