#include <stdio.h>

int fpb(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int kpk(int a, int b) {
    return (a / fpb(a, b)) * b;
}

int main(){

    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d %d",fpb(a,b),kpk(a,b));

    return 0;
}