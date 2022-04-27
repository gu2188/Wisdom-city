#ifndef TWJ_H
#define TWJ_H
#include"reg51.h"
#include"string.h"
#include"intrins.h"
sbit E=P2^2;
sbit RS=P2^0;
sbit RW=P2^1;
sbit DQ=P1^5;
sbit SPACKER=P1^0;
sbit BLUE=P1^7;
sbit RED=P1^6;
#define LCD_DB P0
#define uchar unsigned char
#define uint unsigned int
extern void lcd_csh();
extern uchar lcd_dzt();
extern void lcd_w_cmd(uchar com);
extern void lcd_w_dat(uchar dat);
extern void delay(uint x);
extern void ds18b20_reset();
extern uchar ds18b20_read();
extern void ds18b20_write(uchar dat);
extern uint ds18b20_readtemp();
extern void Temperature_Convert();
extern uint temperature;
extern uchar temp[4];
#endif