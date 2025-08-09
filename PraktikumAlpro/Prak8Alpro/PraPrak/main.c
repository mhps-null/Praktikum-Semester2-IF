#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix A, B;

    // Membaca Matriks A (2x2)
    printf("Masukkan matriks A (2x2):\n");
    readMatrix(&A, 2, 2);
    displayMatrix(A);
    printf("\n");

    // Membaca Matriks B (2x2)
    printf("Masukkan matriks B (2x2):\n");
    readMatrix(&B, 2, 2);
    displayMatrix(B);
    printf("\n");

    // Salinan Matriks A
    Matrix A_copy;
    copyMatrix(A, &A_copy);
    printf("Salinan matriks A:\n");
    displayMatrix(A_copy);
    printf("\n");

    // Membandingkan A dan B
    printf("A == B: %s\n", isMatrixEqual(A, B) ? "true" : "false");
    printf("A != B: %s\n", isMatrixNotEqual(A, B) ? "true" : "false");
    printf("\n");

    // Penjumlahan Matriks A + B
    Matrix C = addMatrix(A, B);
    printf("A + B:\n");
    displayMatrix(C);
    printf("\n");

    // Pengurangan Matriks A - B
    Matrix D = subtractMatrix(A, B);
    printf("A - B:\n");
    displayMatrix(D);
    printf("\n");

    // Perkalian Matriks A * B
    Matrix E = multiplyMatrix(A, B);
    printf("A * B:\n");
    displayMatrix(E);
    printf("\n");

    // Perkalian Matriks A * 2
    Matrix F = multiplyByConst(A, 2);
    printf("A * 2:\n");
    displayMatrix(F);
    printf("\n");

    // Perkalian Matriks B dengan konstanta 3 (in-place)
    pMultiplyByConst(&B, 3);
    printf("B setelah dikali 3:\n");
    displayMatrix(B);
    printf("\n");

    // Negasi Matriks A
    Matrix G = negation(A);
    printf("Negasi A:\n");
    displayMatrix(G);
    printf("\n");

    // Negasi Matriks B (in-place)
    pNegation(&B);
    printf("Negasi B (in-place):\n");
    displayMatrix(B);
    printf("\n");

    // Transpose Matriks A
    Matrix H = transpose(A);
    printf("Transpose dari A:\n");
    displayMatrix(H);
    printf("\n");

    // Transpose Matriks B (in-place)
    pTranspose(&B);
    printf("Transpose dari B (in-place):\n");
    displayMatrix(B);
    printf("\n");

    // Menampilkan informasi tentang A
    printf("A is square: %s\n", isSquare(A) ? "true" : "false");
    printf("A is symmetric: %s\n", isSymmetric(A) ? "true" : "false");
    printf("A is identity: %s\n", isIdentity(A) ? "true" : "false");
    printf("A is sparse: %s\n", isSparse(A) ? "true" : "false");

    // Menghitung determinan A
    printf("Determinan A: %.2f\n", determinant(A));
    
    return 0;
}
