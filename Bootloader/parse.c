#include"main.h"

#define FLASH_START  0x08000000


u32 Address = FLASH_START;
u16 DataToBeFlashed[100];

u8 ASCII_TO_HEX(u8 char_ascii)
{
	u8 res;
	//0 askii->48
	if(char_ascii>='0' && char_ascii<='9')
	{
		res = char_ascii - '0';
	}
	else  //A->65 B->66
	{
		res = char_ascii - '7';
	}
	return res;
}

//:cc add  RT Data                             CS
//: 10 01E0 00 810B0008F5040008F504000800000000 79

void PaeseData(u8 * RecBuffer)
{
	u8 DigitLow=0,DigitHigh=0;
	u8 CC=0;
	u16 Data=0;
	u8 i=0;
//1-
	    DigitHigh = ASCII_TO_HEX (RecBuffer[1]);
		DigitLow  = ASCII_TO_HEX (RecBuffer[2]);
		CC = (DigitHigh<<4) | DigitLow ;
//2-
	//target ->			0x080001E0
	Address = Address & 0xFFFF0000;
	Address = Address | (ASCII_TO_HEX(RecBuffer[3])<<12) | (ASCII_TO_HEX(RecBuffer[4])<<8) | (ASCII_TO_HEX(RecBuffer[5])<<4) | (ASCII_TO_HEX(RecBuffer[6]));
//3-
	for(i=0 ; i<(CC/2) ; i++)
	{														//810B	LSBy->	0000 0000  -  MSBy-> 0000 0000
		Data = (ASCII_TO_HEX(RecBuffer[(i*4)+9]) << 4)  |
			   (ASCII_TO_HEX(RecBuffer[(i*4)+10]))	    |
			   (ASCII_TO_HEX(RecBuffer[(i*4)+11]) << 12)|
			   (ASCII_TO_HEX(RecBuffer[(i*4)+12]) << 8);
		DataToBeFlashed[i]=Data;

	}

	flash_sectorWrite(Address , DataToBeFlashed , CC/2);
}

void ParseUpperAddress(u8 * RecBuffer)
{
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;

	/* Get Address */
	DataDigit0 = ASCII_TO_HEX (RecBuffer[9]);
	DataDigit1 = ASCII_TO_HEX (RecBuffer[10]);
	DataDigit2 = ASCII_TO_HEX (RecBuffer[11]);
	DataDigit3 = ASCII_TO_HEX (RecBuffer[12]);

	/* Clear High Part of Address */
	Address = Address & 0x0000FFFF;
	Address = Address | ((DataDigit0 << 28) | (DataDigit1 << 24) | (DataDigit2 << 20) | (DataDigit3 << 16));

}


void ParseRecord(u8 * RecBuffer)
{
	//:ccxxxxRT
	switch(RecBuffer[8])
	{
	case '0': //data record
		PaeseData(RecBuffer);
		break;
	case '1': //end record
		MGPIO_SetPinValue(GPIO_PORTA, PIN2, VALUE_LOW);
		func_app();

		break;
	case '4':
		ParseUpperAddress(RecBuffer);
		break;
	}
}
