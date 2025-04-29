#include <stdio.h>

int main(){
    int kolom, baris;
    char simbol;

    scanf("%d %d", &baris, &kolom);
    scanf(" %c", &simbol);
    printf("\n");

    for (int i=1;i<=baris;i++)
    {

    for(int j=1;j<=kolom;j++)
    {
        printf("%c", simbol);
    }

    printf("\n");
    }
    printf("\n");
    return 0;
}