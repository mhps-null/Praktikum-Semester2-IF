#include <stdio.h>


int main(){
    FILE *inputFile, *outputFile;
    int nim, nilai, numMahasiswa = 0, totalNilai = 0;

    inputFile=fopen("input.txt","r");outputFile = fopen("output.txt","w");

    if(inputFile == NULL){
        perror("Gagal membuka file input.txt");
        return 1;
    }

    while(fscanf(inputFile, "%d %d", &nim, &nilai)==2){
        if (nim == 99999999 && nilai==-1) break;
        numMahasiswa++;totalNilai+=nilai;
    }

    
    double avgNilai = (numMahasiswa>0) ? (double)totalNilai/numMahasiswa : 0.0 ;

    
    if (outputFile == NULL){
        perror("Gagal");
        return 1;
    }

    fprintf(outputFile,"Jumlah Mahasiswa: %d\n",numMahasiswa);
    fprintf(outputFile,"Nilai rata-rata: %.2f\n",avgNilai);

    fclose(outputFile);fclose(inputFile);
    return 0;
    /*  fgets, fputs, fgetc, fputc
    
        "r"	Baca saja (file harus sudah ada)
        "w"	Tulis, hapus isi lama kalau file sudah ada
        "a"	Tulis, tambahkan di akhir file (append)
        "r+"	Baca dan tulis (file harus ada)
        "w+"	Tulis dan baca, isi lama dihapus
        "a+"	Baca dan append
    */
}