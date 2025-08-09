#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix A, B;
    int N;
    scanf("%d",&N);
    createMatrix(N,N,&A);
    readMatrix(&A,N,N);
    int hasil=-1;
    if(N==1){
        hasil=0;
    }else{
        for(int i=0;i<N;i++){
        int bariskosong=1,kolomsatu=1;
        for(int j=0;j<N;j++){
            if(i==j){continue;}
            else if(A.mem[i][j]!=0){
                bariskosong=0;break;
            }
        }
        for(int k=0;k<N;k++){
            if(i==k){continue;}
            else if(A.mem[k][i]!=1){
                kolomsatu=0;break;
            }
        }
        if(kolomsatu && bariskosong){hasil=i;break;}
    }
    }
    
    printf("%d\n",hasil);

    return 0;
}