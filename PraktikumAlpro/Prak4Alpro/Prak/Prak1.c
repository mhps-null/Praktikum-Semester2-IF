#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

/* Tulis kode disini jika perlu */

int main() {
    init();
    FILE *inputFile, *outputFile;
    inputFile=fopen("input.txt","r");

    int ID,Sukses,Nilai,TotalMisi=0,MisiBerhasil=0,TotalNilai=0;

    if(inputFile == NULL){
        perror("Gagal membuka file input.txt");
        return 1;
    }

    while(fscanf(inputFile,"%d %d %d",&ID,&Sukses,&Nilai)==3){
        if (ID == -1 && Sukses==0 && Nilai==0) break;
        TotalMisi+=1;
        if (Sukses==1){MisiBerhasil++;TotalNilai+=Nilai;}
    }

    

    printf("Total Misi: %d\n",TotalMisi);
    printf("Misi Berhasil: %d\n",MisiBerhasil);
    printf("Total Nilai Misi: %d\n",TotalNilai);


    fclose(inputFile);
    return 0;
}