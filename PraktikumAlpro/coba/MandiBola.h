#include <stdio.h>


int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    return 10000*jumlah_anak+20000*jumlah_dewasa+15000*jumlah_lansia;
}

void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    int total_biaya = HitungBiayaTiket(jumlah_anak,jumlah_dewasa,jumlah_lansia);
    printf("Tiket berhasil dibeli!\nRincian:\n");
    printf("- Jumlah anak-anak: %d\n",jumlah_anak);
    printf("- Jumlah dewasa: %d\n",jumlah_dewasa);
    printf("- Jumlah lansia: %d\n",jumlah_lansia);
    printf("- Total biaya: %d\n", total_biaya);
}


void SelamatDatang(int input){
    int jumlah_anak,jumlah_dewasa,jumlah_lansia;
    jumlah_anak = input%10;
    jumlah_dewasa = (input/10)%10;
    jumlah_lansia = input/100;
    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n\n");
    printf("Jumlah anak: %d\n",jumlah_anak);
    printf("Jumlah dewasa: %d\n", jumlah_dewasa);
    printf("Jumlah lansia: %d\n", jumlah_lansia);
    PrintTiket(jumlah_anak,jumlah_dewasa,jumlah_lansia);
}

void HandleNimonsHunting(long input){
    long jgerak,jlubang,jharta,sejauh,tutup=0,harta=0,jsejauh=0,untung,rugi;
    jgerak = input%10;input/=10;
    jlubang=input%10;input/=10;
    jharta=input%10;input/=10;
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n\n");

    printf("Jumlah pergerakan Nimons di dalam kolam: %ld\n",jgerak);
    printf("Jumlah lubang yang ada di kolam: %ld\n",jlubang);
    printf("Jumlah harta karun yang ada di kolam: %ld\n\n",jharta);

    for(int i=1;i<=jgerak;i++){
        printf("Langkah ke-%d\n",i);
        sejauh=input%10;input/=10;
        if (sejauh==0){
            printf("Nimons tidak bergerak\n");

        }
        else{
        printf("Nimons bergerak sejauh %ld langkah\n",sejauh);}
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

    printf("Total lubang yang ditutup: %d dari %ld lubang\n",tutup,jlubang);
    printf("Total harta karun yang ditemukan: %ld\n",harta);
    untung=(input*harta*5);
    printf("Total harga harta karun yang ditemukan: %ld\n",untung);
    printf("Total langkah yang ditempuh: %ld\n",jsejauh);
    rugi=(input*tutup);
    printf("Total biaya ganti rugi Pak Gro: %ld\n",rugi);
    printf("Total keuntungan Nimons dan Pak Gro: %ld\n",(untung-rugi));
}