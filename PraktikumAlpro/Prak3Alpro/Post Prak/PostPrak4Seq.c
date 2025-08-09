#include <stdio.h>


int main(){
    int N,angka[100001],Q,hasil[100001];

    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d",&angka[i]);
    }
    
    scanf("%d",&Q);
    for (int i=0;i<Q;i++){
        int cari;
        scanf("%d",&cari);
        hasil[i]=-1;
        for (int j=0;j<N;j++){
            if (cari==angka[j]){
                hasil[i]=j;
                break;
        }
        }
    }
    printf("[");
    for (int i=0;i<Q;i++){
        if (i==Q-1){
            printf("%d",hasil[i]);
        }else{printf("%d, ",hasil[i]);}
    }printf("]\n");

    return 0;
}