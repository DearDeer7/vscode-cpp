/**
 * 返回值：键扫描码 （高8 行信号，低8列信号）
 * 功能：调用一次，可以实现对键盘一次全盘扫描 
*/
INT16U ScanKey() {
    INT16U key = 0xffff;
    INT16U i;
    INT8U temp = 0xff, output;

    rGPCCON = rGPCCON & 0xffffff00; //设GPC 0~3 输出
    rGPECON = (rGPECON & 0xfffffc00) | 0x00000155; //设GPE 0~5 输入

    /**
     * 扫描时，循环往键盘（5*4）输出线送低电平
     * 其中输出为5根线，所以循环5次，输入线为4根
     */
    for(i = 1; i <= 16; i <<= 1) {
        // 将第i根输出引脚置低，其余高
        output |= 0xff;
        output &= (~f);
        rGPEDAT = output;

        // 读入键盘输入状态
        temp = rGPCDAT;

        // 判断4根线上是否有低电平出现，若有则有按键输入，否则无
        if((temp & 0x0f) != 0x0f) { 
            key = ~i;
            // 将输出值左移8位，并和读入的值合并为16位键码
            key <<= 8;
            key |= ((temp & 0x0f) | 0xf0);
            return key;
        }
    }

    // 如果没有按键按下，返回0xffff
    return 0xffff;
}

// 数码管
void main() {
    // 共阳极 0 - 9
    char nums[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
    // G口 0 - 7 输出模式
    rGPGCON = (rGPGCON & 0xffff0000) | 0x00005555;
    int i = 0;
    while(1) {
        for(i = 0; i < 10; ++i) {
            rGPGDAT = (rGPGDAT & 0xffffff00) | nums[i];
            delay();
        }
    }
}

// 4个LED跑马驱动
void main() {
    // G口 0-3置输出
    rGPGCON = (rGPGCON & 0xffffff00) | 0x00000055;
    // led闪灯顺序，0，1，2，3 
    char leds[4] = {0xe,0xd,0xb,0x7};
    while(1) {
        for(int i = 0; i < 4; ++i) {
            rGPGDAT = (rGPGDAT & 0xfffffff0) | leds[i];
            delauy();
        }
    }
}

// 一个按键控制一个LED
void main() {
    // LED F 0口
    rGPFCON = (rGPGFCON & 0xfffffff0) | 0x00000001;
    // 开关 G 0口
    rGPGCON = rGPGCON & 0xfffffff0;

    char status; // 开关状态，按下为高电平
    char led = 0x00000000; // LED状态，开始为亮
    while(1) {
        status = rGPGDAT;
        status &= 0x00000001;
        if(status == 1) {

            delay(20); // 消抖
            status = rGPGDAT;
            status &= 0x00000001;

            if(status == 1) { //按下
                rGPFDAT = led;
                led = ~led;
            }
        }
    }
}

; x = a + b
MOV R0, #a
MOV R1, #b
ADD R2, R0, R1 
LDR R3, =0X12345678
STR R2, [R3]

; y = (c - d) + ( e - f);
MOV R0, #c
SUB R0, R0, #d
MOV R1, #e 
SUB R1, R1, #f 
ADD R2, R0, R1 
LDR R3, =0X12345678
STR R2, [R3]

; z = a * (b + c) - d * e
MOV R0, #b 
ADD R0, R0, #c 
MOV R1, #a 
MUL R1, R1, R0 
MOV R2, #d 
MOV R3, #e 
MUL R2, R2, R3
SUB R1, R1, R2 
LDR R3, =0X12345678
STR R1, [R3]