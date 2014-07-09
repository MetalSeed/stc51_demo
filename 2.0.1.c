/**************************一位数码管静态显示（带小数点）*************************************
* 文件名  :  数码管显示.c
* 描述    :  该程序为数码管静态显示程序。
			 程序实现了最右边数码管的显示一个5，大家可以在程序中修改相应的值而在数码管上显示相应的数字。		 

***********************************************************************/
#include<reg52.h>
#define uchar unsigned char
#define uint  unsigned int

//数码管的段码编码
uchar table[16] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
//下一行的数组可以显示数值外，还可以显示数码管的点
uchar table_d[16] = {0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef,0xf7,0xfc,0xb9,0xde,0xf9,0xf1};


/********************************************************************
* 名称 : Main()
* 功能 : 主函数
* 输入 : 无
* 输出 : 无
***********************************************************************/
void main()
{
	uchar i = 0;
	P2 = 7;						 	 //数码管的最后一位显示
	P0 = table_d[5];					 //显示5，大家可以修改里面的数据。
	while(1)
	{		                
	}
}
