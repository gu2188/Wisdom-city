#include<REG52.H>
#define uchar unsigned char
#define uint unsigned int
sbit BUTTOR_ZHEN=P1^0;
sbit BUTTOR_FAN=P1^1;
sbit BUTTOR_JIA=P1^2;
sbit BUTTOR_JIAN=P1^3;
uint code cw[]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};
uint code ccw[]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};
int i,y;
uint speed=500;
void delay(uint x)		
{
    while(x--);
}
int main(void)
{
    while(1)
    {       
                if(BUTTOR_ZHEN==0)
                {
                    for(y=0;y<8;y++)
                    {
                        P0=cw[y];
                        delay(speed);
                    }
                }
                if(BUTTOR_FAN==0)
                {
                    for(y=0;y<8;y++)
                    {
                        P0=ccw[y];
                        delay(speed);
                    }
                }
                if(BUTTOR_JIA==0)
                {
                    speed=speed+100;
                }
                if(BUTTOR_JIAN==0)
                {
                    speed=speed-100;
                    if(speed<500)
                    speed=500;
                }
    }
}