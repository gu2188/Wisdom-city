#include"twj.h"
uchar temp_ADC[6]="";
uint num_GM=0,num_MQ2=0;
void initialize()
{
    P1ASF=0X14;
    ADC_RES=0;
    ADC_CONTR=0X80;
    delay(1200);
}
void adc_GM()
{
    ADC_RES=0;
    ADC_CONTR=0X82;//000=0,001=1,010=2,011=3,100=4,101=5,110=6,111=7
    delay(1200);
    ADC_CONTR=0X8A;
    while(!(ADC_CONTR&0x10));
    ADC_CONTR=0x00;
}
void adc_MQ2()
{
    ADC_RES=0;
    ADC_CONTR=0X84;//000=0,001=1,010=2,011=3,100=4,101=5,110=6,111=7
    delay(1200);
    ADC_CONTR=0X8C;
    while(!(ADC_CONTR&0x10));
    ADC_CONTR=0x00;
}
void xianshi_GM()
{
    uint num=50000-ADC_RES*196,num3=0;
    double num1=50000,num2=0;
    num2=num/num1;
    num3=num2*1000;
    num_GM=num3;
    temp_ADC[0]=(uchar)(num3/1000+'0');
    temp_ADC[1]=(uchar)(num3/100%10+'0');
    temp_ADC[2]=(uchar)(num3/10%10+'0');
    temp_ADC[3]='\.';
    temp_ADC[4]=(uchar)(num3%10+'0');
}
void xianshi_MQ2()
{
    uint num=ADC_RES*196,num3=0;
    double num1=40000,num2=0;
    num2=num/num1;
    num3=num2*1000;
    num_MQ2=num3;
    temp_ADC[0]=(uchar)(num3/1000+'0');
    temp_ADC[1]=(uchar)(num3/100%10+'0');
    temp_ADC[2]=(uchar)(num3/10%10+'0');
    temp_ADC[3]='\.';
    temp_ADC[4]=(uchar)(num3%10+'0');
}