#include <stdio.h>
int stark(int x){
    int cek = x >> 31;
    return x & (~cek);}

int main(){
    int x=-10;
    int hasil = stark(x);
    printf("%d\n",hasil);

    return 0;
}