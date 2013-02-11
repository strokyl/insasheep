//#######################################################################################################################
//
//		AUTHOR: Clément MICHAUD
//		DATE: February 11th, 2013
//		INSTITUTE: INSA Toulouse (France)
//
//		DESCRIPTION: Useful functions 
//
//#######################################################################################################################


#include "utils.h"
#include <string.h>


//**********************************************************************************************
// This function takes a string of the form 0xHHHHHH where H are hexa digits and
// returns the 32bit equivalent variable with the value in it.
// Valid allows the user to check whether the string is valid.
//**********************************************************************************************
u32 getHexFromString(char *str, int *valid){
	int currentChar	= 0;
	u32 addressOut = 0x0000;
	int nbDigits = strlen(str)-2;

	if(str[0] != '0' || str[1] != 'x'){
		*valid = 0;
		return 0;
	}else if(nbDigits > 6){
		*valid = 0;
		return 0;
	}else{
		char c = 1;
		while(c != 0){
			c = str[currentChar+2];
			if(c != 0){
				if((c >= '0' && c <='9')){
					addressOut = addressOut | ((c - '0') << ((nbDigits-1-currentChar)*4));
				}else if(c>='a' && c<='z'){
					addressOut = addressOut | ((c - 'a' + 10) << ((nbDigits-1-currentChar)*4));
				}else{
					*valid = 0;
					return 0;
				}
				//printf("char:%c-%d-%x\n", c, nbDigits, addressOut);
				currentChar++;
			}
		}
	}
	*valid = 1;
	return addressOut;
}

