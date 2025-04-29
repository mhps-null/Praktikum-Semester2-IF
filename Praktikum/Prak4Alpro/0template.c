#include <stdio.h>


int main(){
        FILE *inputFile, *outputFile;
        inputFile=fopen("input.txt","r");outputFile=fopen("output.txt","r");

    if(inputFile == NULL){
        perror("Gagal membuka file input.txt");
        return 1;
    }

    if (outputFile == NULL){
        perror("Gagal");
        return 1;
    }


    fclose(outputFile);fclose(inputFile);
    return 0
}
    