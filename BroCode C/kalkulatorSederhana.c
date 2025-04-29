#include <stdio.h>

int main(){
    char operator;
    double num1;
    double num2;
    double result;

    printf("Masukkan operatornya(+ - * /):\n");
    scanf("%c", &operator);

    printf("Masukkan dua angka yang ingin dioperasikan sesuai urutan:\n");
    scanf("%lf %lf", &num1, &num2);

    switch(operator){
        default:
            printf("Operator tidak valid");
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
    }
    printf("Hasilnya adalah: %.1lf", result);
}