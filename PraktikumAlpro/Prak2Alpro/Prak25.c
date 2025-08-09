#include <stdio.h>

long long kombinasi(int n, int k) {
    if (k > n - k) k = n - k;  // Gunakan properti C(n, k) = C(n, n-k) untuk optimasi
    long long hasil = 1;
    for (int i = 0; i < k; i++) {
        hasil = hasil * (n - i) / (i + 1);
    }
    return hasil;
}

// Fungsi untuk menghitung bilangan Catalan
long long catalan(int n) {
    return kombinasi(2 * n, n) / (n + 1);
}

