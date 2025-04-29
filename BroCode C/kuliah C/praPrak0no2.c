#include <stdio.h>

int main(){
    int i,A,B,nemu,jawaban,maksimum;
    nemu=0; jawaban=0;
    scanf("%d",&A);
    scanf("%d",&B);

    if (A>B){
        maksimum=A;
    } else {
        maksimum=B;
    }

    i=maksimum;

    while (nemu==0){
        if ((A%i==0) && (B%i==0)){
            jawaban=i;
            nemu=1;
        }
        else{
            i--;
        }
    }
    
    printf("%d\n",jawaban);
    return 0;
}