#include <stdio.h>
#include "libraryBuatan.h"

int main(){
    int x,y,Hasil;
    scanf("%d %d", &x, &y);
    Hasil=luaspersegi(x,y);
    printf("%d\n",Hasil);
    printf("\n");

    return 0;
}