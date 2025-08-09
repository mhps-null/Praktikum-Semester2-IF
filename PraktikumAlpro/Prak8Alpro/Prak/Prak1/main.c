#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix A;
    int nRow,nCol;
    scanf("%d",&nRow);
    scanf("%d",&nCol);
    createMatrix(nRow,nCol,&A);
    readMatrix(&A,nRow,nCol);
    int count=0;
    for(int i=0;i<A.rowEff;i++){
        for(int j=0;j<A.colEff;j++){
            int max=A.mem[i][j],min=A.mem[i][j];
            for(int k=0;k<A.colEff;k++){
                if(A.mem[i][k]<min){
                    min=-999;
                    break;
                }
            }
            for(int r=0;r<A.rowEff;r++){
                if(A.mem[r][j]>max){
                    max=-999;
                    break;
                }
            }
            if(max==A.mem[i][j] && min==A.mem[i][j]){
                count++;
                printf("(%d,%d,%d)\n",i,j,A.mem[i][j]);
            }
        }
    }
    printf("%d\n",count);
}