#include <stdio.h>

#define MAX_N 100  // Batas atas untuk N

// Fungsi untuk mengecek apakah sebuah angka adalah bilangan prima
int is_prime(int num) {
    if (num < 2) return 0;  // 0 berarti false
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;  // 0 berarti false
    }
    return 1;  // 1 berarti true
}

// Fungsi untuk mengisi array dengan bilangan prima pertama sebanyak count
void generate_primes(int primes[], int count) {
    int num = 2, idx = 0;
    while (idx < count) {
        if (is_prime(num)) {
            primes[idx++] = num;
        }
        num++;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    if (N < 1) {
        printf("Tidak valid\n");
        return 0;
    }

    int primes[MAX_N * MAX_N];  // Array untuk menyimpan bilangan prima
    generate_primes(primes, N * N);

    int matrix[MAX_N][MAX_N];

    // Mengisi diagonal utama dan bagian kanan
    for (int i = 0; i < N; i++) {
        int idx = i;  // Indeks dalam array bilangan prima
        for (int j = i; j < N; j++) {
            matrix[i][j] = primes[idx++];
        }
    }

    // Mengisi bagian bawah diagonal utama dengan refleksi
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            matrix[i][j] = matrix[j][i];  // Cerminan dari atas diagonal utama
        }
    }

    // Cetak hasil
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", matrix[i][j]);
            if (j < N - 1) printf(" ");  // Hindari spasi di akhir baris
        }
        printf("\n");  // Baris baru setelah setiap baris matriks
    }

    return 0;
}
