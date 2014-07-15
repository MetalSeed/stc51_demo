/********************************************************************
* 文件名  ： 定时器的使用.c
* 描述    :  用定时器方式2的程序代码。
			 相对前面的软件延时，定时器的延时更为精确。
			 晶振大小为11.0592，延时时间为0.1毫秒。
			 所以延时10000次，为一秒。

***********************************************************************/
#include<reg52.h>
#define uchar unsigned char
#define uint  unsigned int 

uint Count = 0;
uchar code table[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
/********************************************************************
* 名称 : Time0_Init()
* 功能 : 定时器的初始化，11.0592MZ晶振，0.1ms
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Time0_Init()
{
	TMOD = 0x02;	
	TH0  = 0xA3;
	TL0  = 0xA3;
	IE 	 = 0x82;	
	TR0 = 1;		
}
										 
/********************************************************************
* 名称 : Time0_Int()
* 功能 : 定时器中断，中断中实现 Count 加一
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Time0_Int() interrupt 1
{
	Count++;			//长度加1
}

/********************************************************************
* 名称 : Main()
* 功能 : 主函数
* 输入 : 无
* 输出 : 无
***********************************************************************/
void main()
{
	uchar i = 0;
	Time0_Init();
	P2 = 7;
	while(1)
	{
		P0 = table[i % 10];	  //取 i 的个位
		while(1)
		{
			if(Count == 10000)	  //当Count为 10000 时，i 自加一次，10000 * 0.1MS = 1S
			{
				Count = 0;
				i++;
				break;
			}
		}
	}
}
