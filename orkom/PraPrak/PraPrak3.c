#include <stdio.h>

unsigned int fern(unsigned int x){
     int ganjil=(x & 0x55)<<1;
     int genap=(x & 0xAA)>>1;
    return ganjil|genap;
}

int main(){
    unsigned int hasil=fern(0b1001);
    printf("%#x\n",hasil);

    return 0;
}