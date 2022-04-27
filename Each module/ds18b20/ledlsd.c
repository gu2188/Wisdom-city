#include"twj.h"
uchar str[]="temp:";
uchar str1[]="temp to hot";
uchar str2[]="01200111 45";
uint code cw[]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};
int main(void)
{
    uchar g;
    RED=0;
    BLUE=1;
    P0=0xff;
    delay(10);
    lcd_csh();
    delay(10);
    lcd_w_cmd(0x80);
    delay(10);
    for ( g = 0;str[g] !='\0'; g++)
    {
        lcd_w_dat(str[g]);
    }
    lcd_w_cmd(0x89);
    lcd_w_dat(0xdf);
    lcd_w_dat('C');
    lcd_w_cmd(0xc0);
    delay(10);
    for ( g = 0;str2[g] !='\0'; g++)
    {
        lcd_w_dat(str2[g]);
    }
    while (1)
    {
    lcd_w_cmd(0x85);
    ds18b20_readtemp();
    Temperature_Convert();
    for ( g = 0;g<4; g++)
    {
        lcd_w_dat(temp[g]);
        delay(100);
    }
    if(temperature>280&&temperature!=850)
    { 
            P0=0xff;
            BLUE=0;
            delay(10);
            lcd_csh();
            delay(10);
            lcd_w_cmd(0x80);
            delay(10);
            for ( g = 0;str1[g] !='\0'; g++)
            {
                lcd_w_dat(str1[g]);
            }
            while(1)
            {
                ds18b20_readtemp();
                SPACKER=1;
                RED=1;
                for(g=0;g<8;g++)
                {
                    P3=cw[g];
                    delay(650);
                }
                SPACKER=0;
                RED=0;
                for(g=0;g<8;g++)
                {
                    P3=cw[g];
                    delay(650);
                }
                for(g=0;g<8;g++)
                {
                    P3=cw[g];
                    delay(650);
                }
                P3=0x00;
                if(temperature<=280)
                {
                        RED=0;
                        BLUE=1;
                        P0=0xff;
                        delay(10);
                        lcd_csh();
                        delay(10);
                        lcd_w_cmd(0x80);
                        delay(10);
                        for ( g = 0;str[g] !='\0'; g++)
                        {
                            lcd_w_dat(str[g]);
                        }
                        lcd_w_cmd(0x89);
                        lcd_w_dat(0xdf);
                        lcd_w_dat('C');
                        lcd_w_cmd(0xc0);
                        break;
                }
            }
    }
    }
}