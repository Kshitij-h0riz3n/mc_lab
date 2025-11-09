#include<reg51.h>
void delay()
{
    TMOD = Ox01;
    TL0=0xFC;
    TH0=0x66;
    TR0=1;
    while(TF0==0);
    TR0=0;
    TF0=0;
}

void main (void)
{
    while(1)
    {
        // All on all off
        P2=0xFF;
        delay();
        P2=0x00;
        delay();
        // Alterntae on off
        // P2=0xAA;
        // delay();
        // P2=0x55;
        // delay();
        // 4 on 4 off
        // P2=0xF0;
        // delay();
        // P2=0x0F;
        // delay();
        // toggle skip 2
        // P2=0x33;
        // delay();
        // P2=0xCC;
        // delay();
    }

}
