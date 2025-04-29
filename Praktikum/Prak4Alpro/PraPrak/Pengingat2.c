#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char buffer[256]; // untuk menyimpan satu baris
    int charCount = 0;
    int c; // untuk fgetc

    // Buka file input
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Gagal membuka input.txt");
        return 1;
    }

    // Buka file output
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Gagal membuka output.txt");
        fclose(inputFile);
        return 1;
    }

    // ======= Membaca baris demi baris dengan fgets, lalu tulis ke output.txt =======
    while (fgets(buffer, sizeof(buffer), inputFile)) {
        fputs(buffer, outputFile);  // tulis baris ke output
    }

    // Reset file ke awal lagi
    rewind(inputFile);

    printf("Isi file karakter demi karakter:\n");

    // ======= Baca karakter per karakter pakai fgetc =======
    while ((c = fgetc(inputFile)) != EOF) {
        charCount++;
        fputc(c, stdout); // tampilkan ke terminal (stdout)
    }

    printf("\nJumlah karakter: %d\n", charCount);

    // Tutup file
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
