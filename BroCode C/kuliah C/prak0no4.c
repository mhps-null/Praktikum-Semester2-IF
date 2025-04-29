#include <stdio.h>

typedef struct{
    int HH;
    int MM;
    int SS;
}Jam;

int main(){
    Jam waktu,waktu2,selisih;
    
    scanf("%d %d %d", &waktu.HH, &waktu.MM, &waktu.SS);
    scanf("%d %d %d", &waktu2.HH, &waktu2.MM, &waktu2.SS);
    
    selisih.HH=waktu2.HH-waktu.HH;
    selisih.MM=waktu2.MM-waktu.MM;
    selisih.SS=waktu2.SS-waktu.SS;

    printf("%d %d %d\n",selisih.HH,selisih.MM,selisih.SS);
    

    return 0;
}