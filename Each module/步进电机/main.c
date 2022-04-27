#include"reg51.h"
#include"string.h"
#include"intrins.h"
#define uchar unsigned char
#define uint unsigned int
void delay(uint x)		
{
    while(x--);
    
}
uint code cw[]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};
uint code ccw[]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};
int main(void)
{
	uchar g=0;
	int i;
	for(i=0;i<512;i++)
	{ 
			for(g=0;g<8;g++)
      {
				P3=cw[g];
				delay(600);
      }
	}
	delay(2000);
	for(i=0;i<512;i++)
	{ 
			for(g=0;g<8;g++)
      {
				P3=ccw[g];
				delay(1600);
      }
	}
	P3=0;
	return 0;
}