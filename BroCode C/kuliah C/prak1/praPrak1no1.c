#include <stdio.h>

int main(){
    int N,i,pertama,kedua,hasil;
    scanf("%d",&N);
    i=1;
    pertama=0; kedua=1;

    while (i<N){
        i+=1;
        printf("%d ",pertama);
        hasil=pertama+kedua;
        pertama=kedua;
        kedua=hasil;
    }

    printf("%d\n",pertama);
    
    return 0;
}