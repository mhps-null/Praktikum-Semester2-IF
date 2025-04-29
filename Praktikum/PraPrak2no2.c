#include <stdio.h>


int main(){
    long long int input;
    // scanf("%d",&input2);
    input=100114112115000554LL;
    long long int jgerak,jlubang,jharta,sejauh,tutup=0,harta=0,jsejauh=0,untung,rugi;
    jgerak = input%10;input/=10;
    jlubang=input%10;input/=10;
    jharta=input%10;input/=10;
    // printf("%lld",input);
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n\n");

    printf("Jumlah pergerakan Nimons di dalam kolam: %d\n",jgerak);
    printf("Jumlah lubang yang ada di kolam: %d\n",jlubang);
    printf("Jumlah harta karun yang ada di kolam: %d\n\n",jharta);

    for(int i=1;i<=jgerak;i++){
        printf("Langkah ke-%d\n",i);
        sejauh=input%10;input/=10;
        if (sejauh==0){
            printf("Nimons tidak bergerak\n");

        }
        else{
        printf("Nimons bergerak sejauh %d langkah\n",sejauh);}
        jsejauh+=sejauh;
        if ((input%10)==1){
            printf("Nimons menemukan harta karun!\n");
            input/=10;harta+=1;
        }else{input/=10;}
        if ((input%10)==1){
            printf("Nimons menutup lubang!\n\n");
            input/=10;tutup+=1;
        }else{input/=10;}
    }

    printf("Total lubang yang ditutup: %d dari %d lubang\n",tutup,jlubang);
    printf("Total harta karun yang ditemukan: %d\n",harta);
    untung=(input*harta*5);
    printf("Total harga harta karun yang ditemukan: %d\n",untung);
    printf("Total langkah yang ditempuh: %d\n",jsejauh);
    rugi=(input*tutup);
    printf("Total biaya ganti rugi Pak Gro: %d\n",rugi);
    printf("Total keuntungan Nimons dan Pak Gro: %d\n",(untung-rugi));
    return 0;
}