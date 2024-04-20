#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,Count;

void main()
{
		LCD_Init();
		LCD_ShowString(1,1,"Password:");
		while(1)
		{
			KeyNum=MatrixKey();
			if(KeyNum!=0)
			{
				if(KeyNum<=10)            //S1~S13
				{
					if(Count<4)             //输入次数4
					{
						Password*=10; 			  //左移一位
						Password+=KeyNum%10;  //获取密码
						Count++;
					}
					LCD_ShowNum(2,1,Password,4);
				}
				if(KeyNum==14)           //S14确认
				{
					if(Password==2345)
					{
						LCD_ShowString(1,13,"OK__");
						Password=0;
						Count=0;
					}
					else								//"错误"
					{
						LCD_ShowString(1,13,"MISS");
						Password=0;
						Count=0;
						Delay(800);
						LCD_ShowNum(2,1,Password,4);
					}
				}
				if(KeyNum==15)         //S15取消键
				Password=0;
				Count=0;
				LCD_ShowNum(2,1,Password,4);
			}	
			
			
		}
}