/********************************************************************
* 描述    :  点亮P1口的一个LED灯
        	 该程序是单片机学习中最简单最基础的，
			 通过程序了解如何控制端口的高低电平		 

***********************************************************************/
#include<reg52.h>
#define uchar unsigned char   //这里用"uchar"代替"unsigned char"，"uchar"用来定义无符号字符型数。
#define uint  unsigned int	  //"uint"用来定义无符号整型数。
sbit Show_LED = P0^0;		  //用来声明P1.0口为程序所要控制的端口,"sbit"是KEIL专门用来声明某位IO口											  

/********************************************************************
* 名称 : Main()
* 功能 : 实现灯的闪烁
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Main(void)
{
	Show_LED = 0;    //点亮P1.0对应的LED
	while(1)
	{
	}
}

/********************************************************************
* 描述    :  点亮P1口的一个LED灯
        	 该程序是单片机学习中最简单最基础的，
			 通过程序了解如何控制端口的高低电平	 

***********************************************************************/
#include<reg52.h>
#define uchar unsigned char   //这里用"uchar"代替"unsigned char"，"uchar"用来定义无符号字符型数。
#define uint  unsigned int	  //"uint"用来定义无符号整型数。						  

/********************************************************************
* 名称 : Main()
* 功能 : 实现灯的闪烁
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Main(void)
{
	P0 = 0xfe;				//点亮最后一个LED
	while(1)
	{
	}
}
