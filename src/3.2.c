/********************************************************************
* 文件名  ： 点阵显示.c
* 描述    :  这个代码在点阵上显示相应的图形。
***********************************************************************/
#include <reg52.H>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
//心形显示
unsigned char tabP0[]={0x00,0x10,0x30,0x7E,0x7E,0x30,0x10,0x00};
unsigned char tabP2[]={0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE};
unsigned char TEMP[8];

//圆形显示
//unsigned char code tabP0[]={0x00,0x3c,0x42,0x42,0x42,0x42,0x3c,0x00};
//unsigned char code tabP2[]={0x7F,0xBF,0x0DF,0x0EF,0x0F7,0x0FB,0x0FD,0x0FE};

//菱形显示
//unsigned char code tabP0[]={0x00,0x08,0x14,0x22,0x41,0x22,0x14,0x08};
//unsigned char code tabP2[]={0x7F,0xBF,0x0DF,0x0EF,0x0F7,0x0FB,0x0FD,0x0FE};

//叉形显示
//unsigned char code tabP0[]={0x00,0x41,0x22,0x14,0x08,0x14,0x22,0x41};
//unsigned char code tabP2[]={0x7F,0xBF,0x0DF,0x0EF,0x0F7,0x0FB,0x0FD,0x0FE};

//中字显示
//unsigned char code tabP0[]={0x00,0x1e,0x12,0x12,0x7f,0x12,0x12,0x1e};
//unsigned char code tabP2[]={0x7F,0xBF,0x0DF,0x0EF,0x0F7,0x0FB,0x0FD,0x0FE};

/********************************************************************
* 名称 : Delay_1ms()
* 功能 : 延时子程序，延时时间为 1ms * x
* 输入 : x (延时一毫秒的个数)
* 输出 : 无
***********************************************************************/
void Delay_1ms(uchar i)//1ms延时
{
	uchar x,j;
	for(j=0;j<i;j++)
	for(x=0;x<=148;x++);	
}
/********************************************************************
* 名称 : Main()
* 功能 : 主函数
* 输入 : 无
* 输出 : 无
***********************************************************************/
void main()
{
	uchar i,j,temp=0;
	for(i=0;i<8;i++)
	{
		TEMP[i]=tabP0[i];
	}
	while(1)
	{
		for(j=0;j<8;j++)
		{
			for(i=0;i<8;i++)
			{
				P0=0;
				P2=tabP2[i]; 		
				P0=tabP0[i];
				Delay_1ms(2);

			}
		}
		for(i=0;i<8;i++)
		{
			TEMP[i]=_crol_(TEMP[i],1);
			tabP0[i]=TEMP[i];	
		}				
	}
}
