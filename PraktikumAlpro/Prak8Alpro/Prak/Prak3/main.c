#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix A;
    int N,M,K,X;int count=0;
    scanf("%d %d %d %d",&N,&M,&K,&X);
    createMatrix(N,M,&A);
    readMatrix(&A,N,M);
    for(int i=0;i<=N-K;i++){
        for (int j=0;j<=M-K;j++){
            int sum=0;
            for(int a=0;a<K;a++){
                for(int b=0;b<K;b++){
                    sum+=A.mem[i+a][j+b];
                }
            }
            if(sum<=X){count++;}
        }
    }
    printf("%d\n",count);
    return 0;
}