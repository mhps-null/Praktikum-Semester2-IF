#include <stdio.h>

unsigned int ubel(unsigned int x) {
    unsigned int result = 0;
    int i;
    
    for (i = 0; i < 32; i++) {
        unsigned int bit = (x >> i) & 1;
        result = result | (bit << (31 - i));
    }
    
    return result;
}

int main(){
    
    printf("%u\n",ubel(0b00000000000000000000000000000001));

    return 0;
}