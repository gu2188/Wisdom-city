#ifndef TWJ_H
#define TWJ_H
#include"reg51.h"
#include"string.h"
#include"intrins.h"
sbit E=P2^2;
sbit RS=P2^0;
sbit RW=P2^1;
sbit DQ=P1^5;
sbit BB=P1^0;
sbit BULLE=P1^7;
sbit RED=P1^6;
#define LCD_DB P0
#define uchar unsigned char
#define uint unsigned int
extern void lcd_csh();
extern uchar lcd_dzt();
extern void lcd_w_cmd(uchar com);
extern void lcd_w_dat(uchar dat);
extern void delay(uint x);
extern void initialize();
extern void adc_GM();
extern void adc_MQ2();
extern void xianshi_GM();
extern void xianshi_MQ2();
extern uint ds18b20_readtemp();
extern void Temperature_Convert();
extern uchar temp_DS18B20[4];
extern uchar temp_ADC[6];
extern uint temperature;
extern uint num_GM,num_MQ2;
sfr ADC_CONTR=0XBC;
sfr ADC_RES=0XBD;
sfr ADC_RESL=0XBE;
sfr AUXR1=0XA2; 
sfr IPH=0XB7;   
sfr P1ASF=0X9D;
#endif