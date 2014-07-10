/********************************************************************
* 文件名  :  步进电机.c
* 描述    :  按键的长短键操作。
             按了按键后，数码管的值加减1。
			 如果长按住，会发现数码管快速加减。
			 			 

***********************************************************************/
#include <reg52.h> 
#define uchar unsigned char
#define uint  unsigned int

sbit KEY1 = P3^2;	//数码管的值加1	  "S19" 
sbit KEY2 = P3^4;   //数码管的值减1	  "S17"

uint angle = 100;

uchar code table[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
/********************************************************************
* 名称 : Delay_1ms()
* 功能 : 延时子程序，延时时间为 1ms * x
* 输入 : x (延时一毫秒的个数)
* 输出 : 无
***********************************************************************/
void Delay(uint i)
{
	uchar x,j;
	for(j=0;j<i;j++)
	for(x=0;x<=148;x++);	
}

/********************************************************************
* 名称 : Delay_LED()
* 功能 : 延时代码，延时3毫秒，在延时中加入了数码管的显示，防止按键时抖动
* 输入 : del
* 输出 : 无
***********************************************************************/
void Delay_LED(uchar del)
{
	uchar i;
	for(i=0;i<del;i++)
	{
		P0 = 0x00;
		P2 = 7;
		P0 = table[angle%10];
		Delay(1); 
		
		P0 = 0x00;		
		P2 = 6;
		P0 = table[angle/10%10];
		Delay(1); 
				
		P0 = 0x00;
		P2 = 5;
		P0 = table[angle/100%10];
		Delay(1);
	}	
}

void KEY(void)
{
	if((KEY2 == 0) && (angle > 0))		//按P3.4，数码管的值减1
	{
		Delay(15);
		if((KEY2 == 0) && (angle > 0))
		{
			angle--;
		}
		Delay_LED(100);
		if((KEY2 == 0) && (angle > 0))
		{
			Delay_LED(100);
			angle--;
			if((KEY2 == 0) && (angle > 0))
			{
				Delay_LED(80);
				angle--;
				while(1)						  	//进入循环，里面进行长键检测
				{
					if((KEY2 == 0) && (angle > 0))
					{
						angle--;
						Delay_LED(20);	
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	if(KEY1 == 0)		//按P3.4，数码管的值加1
	{
		Delay_LED(15);
		if(KEY1 == 0)
		{
			angle++;
		}
		Delay_LED(100);
		if(KEY1 == 0)
		{
			Delay_LED(100);
			angle++;
			if(KEY1 == 0)
			{
				Delay_LED(80);
				angle++;
				while(1)					  //进入循环，里面进行长键检测
				{
					if(KEY1 == 0)
					{
						angle++;
						Delay_LED(20);	
					}
					else
					{
						break;
					}
				}
			}
		}
	}
}

main()
{
	while(1)
	{
		KEY();
		Delay_LED(1);
	}	
}
