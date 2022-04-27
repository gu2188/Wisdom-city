#include"twj.h"
void main()
{
    uchar g;
    P0=0xff;
    delay(10);
    lcd_csh();
    delay(10);
    lcd_w_cmd(0x80);
    delay(10);
        while (1)
        {
            lcd_w_cmd(0x80);
            delay(10);
            initialize();
            adc_zhuanhuan();
            xianshi();
            for(g=0;g<4;g++)
            {
                lcd_w_dat(temp[g]);
                delay(1000);
            }
        }
}