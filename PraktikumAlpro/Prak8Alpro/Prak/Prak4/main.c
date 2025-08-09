#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix A, B;
    int nRow,nCol;
    scanf("%d",&A);
    createMatrix(nRow,nCol,&A);
    readMatrix(&A,nRow,nCol);
}