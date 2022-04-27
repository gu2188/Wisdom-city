#include"twj.h"
void lcd_csh()
{
    lcd_w_cmd(0x3c);
    lcd_w_cmd(0x0c);
    lcd_w_cmd(0x01);
    lcd_w_cmd(0x06);
}
uchar lcd_dzt()
{
    uchar s;
    RW=1;
    delay(200);
    RS=0;
    delay(200);
    E=1;
    delay(200);
    s=LCD_DB;
    delay(200);
    E=0;
    delay(200);
    RW=0;
    delay(200);
    return(s);
}
void lcd_w_cmd(uchar com)
{
    uchar i;
    do
    {
        i=lcd_dzt();
        i=i&0x80;
        delay(200);
    }
    while (i!=0);
    RW=0;
    delay(200);
    RS=0;
    delay(200);
    E=1;
    delay(200);
    LCD_DB=com;
    delay(200);
    E=0;
    delay(200);
    RW=1;
    delay(200);
}
void lcd_w_dat(uchar dat)
{
    uchar i;
    do
    {
        i=lcd_dzt();
        i=i&0x80;
        delay(200);
    }
    while (i!=0);
    RW=0;
    delay(200);
    RS=1;
    delay(200);
    E=1;
    delay(200);
    LCD_DB=dat;
    delay(200);
    E=0;
    delay(200);
    RW=1;
    delay(200);
}