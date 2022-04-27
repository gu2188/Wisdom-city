#ifndef TWJ_H
#define TWJ_H
#include"reg51.h"
#include"string.h"
#include"intrins.h"
sbit E=P2^2;
sbit RS=P2^0;
sbit RW=P2^1;
sbit DQ=P1^1;
#define LCD_DB P0
#define uchar unsigned char
#define uint unsigned int
extern void lcd_csh();
extern uchar lcd_dzt();
extern void lcd_w_cmd(uchar com);
extern void lcd_w_dat(uchar dat);
extern void delay(uint x);
extern void initialize();
extern void adc_zhuanhuan();
extern void xianshi();
extern uchar temp[6];
sfr ADC_CONTR=0XBC;
sfr ADC_RES=0XBD;
sfr ADC_RESL=0XBE;
sfr AUXR1=0XA2; 
sfr IPH=0XB7;   
sfr P1ASF=0X9D;
#endif