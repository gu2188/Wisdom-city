#include"twj.h"
uchar temp[6]="";
void initialize()
{
    P1ASF=0X04;
    ADC_RES=0;
    ADC_CONTR=0X80;
    delay(1400);
}
void adc_zhuanhuan()
{
    ADC_RES=0;
    ADC_CONTR=0X82;
    delay(1400);
    ADC_CONTR=0X8A;
    while(!(ADC_CONTR&0x10));
    ADC_CONTR=0x00;
}
void xianshi()
{
    uint num=ADC_RES*196;
    temp[0]=(uchar)(num/10000+'0');
    temp[1]='\.';
    temp[2]=(uchar)(num/1000%10+'0');
    temp[3]=(uchar)(num/100%10+'0');
}
