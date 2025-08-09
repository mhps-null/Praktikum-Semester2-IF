#include <stdio.h>

void SWAP(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x=1,y=2;
    SWAP(&x,&y);
    printf("%d %d",x,y);

    return 0;
}
