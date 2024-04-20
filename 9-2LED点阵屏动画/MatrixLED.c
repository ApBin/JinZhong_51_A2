#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;  //RCLK
sbit SCK=P3^6;	//SRCLK
sbit SER=P3^4;	//SER

#define MATRIXAD_LED_PORT			P0
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte>>7;
		Byte<<=1;
		SCK=0;
		//Delay(1);
		SCK=1;
		//Delay(1);
	}
	RCK=0;
	//Delay(1);
	RCK=1;
}

void MatrixLED_Init()
{
	SCK=0;
	RCK=0;
}
/*
* @brief  	LED点阵屏显示一列数据
* @param		Column 要选择的列，范围0~7，0在最左
* @param	 Data 要选择的列显示的数据，高位在上，1为亮，0为灭
* @retval		无
*/
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);
	MATRIXAD_LED_PORT=~(0x80>>Column);
	Delay(1);
	MATRIXAD_LED_PORT=0xFF;
	
}
