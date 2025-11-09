#include <reg51.h>

void delay_ms(unsigned int ms) {
    unsigned int i;
    for (i = 0; i < ms; i++) {
        TH0 = 0xFC;
        TL0 = 0x66;
        TR0 = 1;
        while (TF0 == 1);
        while (TF0 == 0);
        TR0 = 0;
        TF0 = 0;
    }
}

unsigned char codes[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void main(void) {
    int k;
    TMOD = (TMOD & 0xF0) | 0x01;
    TF0 = 0;
    TR0 = 0;
    while (1) {
        for (k = 0; k < 10; k++) {
            P2 = codes[k];
            delay_ms(500);
        }
    }
}
