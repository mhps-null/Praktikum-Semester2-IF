#include <stdio.h>


int main(){
    int input_1,anak,dewasa,lansia,harga;
    scanf("%d",&input_1);
    lansia=input_1/100;
    
    lansia=lansia%10;

    dewasa=(input_1/10)%10;

    anak=input_1%10;
    harga=(10000*anak)+(20000*dewasa)+(15000*lansia);
    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n\n");
    printf("Harga tiket:\n");
    printf("Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("Lansia (usia 65 tahun ke atas): Rp 15000\n\n");

    printf("Jumlah anak: %d\n",anak);
    printf("Jumlah dewasa: %d\n",dewasa);
    printf("Jumlah lansia: %d\n",lansia);
    printf("Tiket berhasil dibeli!\n\n");

    printf("Rincian:\n");
    printf("Jumlah anak-anak: %d\n",anak);
    printf("Jumlah dewasa: %d\n",dewasa);
    printf("Jumlah lansia: %d\n",lansia);
    printf("Total biaya: %d\n",harga);
    printf("----------------------------------------\n");

    return 0;
}