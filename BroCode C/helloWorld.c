#include <stdio.h>
#include <math.h>

int main(){

    double sisiA;
    double sisiB;
    double sisiMiring;

    printf("Masukkan sisi A:\n ");
    scanf("%lf", &sisiA);

    printf("Masukkan sisi B:\n ");
    scanf("%lf", &sisiB);

    sisiMiring = sqrt(pow(sisiA, 2) + pow(sisiB, 2));

    printf("Sisi miring adalah: %.2lf", sisiMiring);

    return 0;
}