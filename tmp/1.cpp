/**
 * Created by DearDeer on 2020/11/06
 * led shuffle back and forth
 */
#include<reg52.h>
#include<intrins.h>

#define uint unsigned int
#define uchar unsigned char

sbit beep = P2^3;

void delay(uint t) {
    uint i, j;
    for(i = 0; i < 100; ++i) {
        for(j = 0; j < t; ++j) ;
    }
}

void main() {
	
    uint i;
    P1 = 0xfe;
    delay(100);

    while(1) {
        
        for(i = 0; i < 7; ++i) {
            P1 = _crol_(P1, 1);
            delay(100);
        }
    
        P1 = 0xfe;

        for(i = 0; i < 7; ++i) {
            P1 = _cror_(P1, 1);
            delay(100);
        }
    }
}