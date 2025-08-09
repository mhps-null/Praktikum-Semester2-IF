#include <stdio.h>
#include <stdlib.h>
// #include "tester.h"

/* Tulis kode disini jika perlu */

int main() {
    // init();
    /* Tulis kode dibawa ini */
    FILE *inputFile, *outputFile;
    int ID1,Sukses1,Nilai1,ID[2002],Nilai[1002],Sukses[1002];int k,l,n;
    inputFile=fopen("input.txt","r");// TODO: baca file input.txt
    while(fscanf(inputFile,"%d %d %d",&ID1,&Sukses1,&Nilai1)==3){
        ID[ID1]=ID1;Nilai[ID1]=Nilai1;Sukses[ID1]=Sukses1;
    }

    for(int i = 1;i<1000;i++){
        if(Sukses[i]==1){
            for(int j =i+1;j<1001;j++){
                if (Sukses[j]==0){
                    int temp = Nilai[i];
                    Nilai[i]=Nilai[j];
                    Nilai[j]=temp;
                    int temp1 = ID[i];
                    ID[i]=ID[j];
                    ID[j]=temp1;
                }
            }
        } 
    }

    for(int i = 1;i<1000;i++){
            for(int j =i+1;j<1001;j++){
                if (Nilai[i]>Nilai[j]){
                    int temp = Nilai[i];
                    Nilai[i]=Nilai[j];
                    Nilai[j]=temp;
                    int temp1 = ID[i];
                    ID[i]=ID[j];
                    ID[j]=temp1;
                }
            }
    }
    printf("%d %d %d",ID[1],Nilai[1],Sukses[1]);
    fclose(inputFile);
    inputFile=fopen("query.txt","r");// TODO: baca file query.txt
    while(fscanf(inputFile,"%d",&k)==2){
        for(int m=1;m<=k;m++){
            fscanf(inputFile,"%d",&n);
            printf("%d %d\n",ID[n],Nilai[n]);
        }
        
    }
    fclose(inputFile);
    // TODO: tulis kode untuk algoritma utama
    // TODO: close file input.txt
    // TODO: close file query.txt
    return 0;
}