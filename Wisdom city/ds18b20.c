#include"twj.h"
uint temperature=0;
uchar temp_DS18B20[4]="    ";
void ds18b20_reset()
{
    uchar x=1;
    DQ=1;
    delay(60);
    DQ=0;
    delay(700);
    DQ=1;
    delay(90);
    x=DQ;
    while(x);
    delay(330);
    DQ=1;
}

uchar ds18b20_read()
{
    uchar i=0,dat=0;
    for(i=8;i>0;i--)
    {
        dat>>=1;
        DQ=0;
        delay(6);
        DQ=1;
        delay(6);
        if(DQ)
        dat|=0x80;
        delay(60);
    }
    return(dat);
}

void ds18b20_write(uchar dat)
{
    uchar i=0;
    for(i=8;i>0;i--)
    {
        DQ=0;
        delay(6);
        DQ=dat&0x01;
        dat>>=1;
        delay(60);
        DQ=1;
    }
}

uint ds18b20_readtemp()
{
    uchar TPL=0;
    uchar TPH=0;
    float t=0;
    EA=0;
    ds18b20_reset();
    ds18b20_write(0xcc);
    ds18b20_write(0x44);
    while(!DQ);
    ds18b20_reset();
    ds18b20_write(0xcc);
    ds18b20_write(0xbe);
    TPL=ds18b20_read();
    TPH=ds18b20_read();
    temperature=TPH;
    temperature<<=8;
    temperature=temperature|TPL;
    t=temperature*0.0625;
    temperature=t*10+0.5;
    return(temperature);
}
void Temperature_Convert()
{   
    temp_DS18B20[0]=(uchar)(temperature/100+'0');
    temp_DS18B20[1]=(uchar)(temperature%100/10+'0');
    temp_DS18B20[2]='\.';
    temp_DS18B20[3]=(uchar)(temperature%10+'0');
}	