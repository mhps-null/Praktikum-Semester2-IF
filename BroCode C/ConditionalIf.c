#include <stdio.h>

int main(){

    int umur;
    
    printf("Berapa umur kamu syg?\n");
    scanf("%d",&umur);

    // if (umur>=18){
    //     printf("Kamu sudah cukup dewasa untuk mendampingi perjalananku");
    // }

    switch(umur){
        case 0:
            printf("Kamu belum lahir");
            break;
        case 1:
            printf("Kamu belum 1");
            break;
        case 2:
            printf("Kamu belum 2");
            break;
    }
}