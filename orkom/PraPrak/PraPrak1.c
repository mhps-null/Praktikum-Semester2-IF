#include <stdio.h>

int sein(int x,int y){
    return((x&~y)|(~x&y));
}

int main(){
    
    printf("%d\n",sein(5,3));

    return 0;
}