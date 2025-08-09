#include <stdio.h>

// Fungsi untuk mengecek apakah tahun kabisat
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Fungsi untuk mendapatkan jumlah hari dalam suatu bulan
int getDaysInMonth(int month, int year) {
    if (month < 1 || month > 12) return 0; // Menangani bulan tidak valid
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) return 29;
    return daysInMonth[month - 1];
}

// Fungsi untuk mengecek apakah tanggal valid
int isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12) return 0;
    return (day >= 1 && day <= getDaysInMonth(month, year));
}

// Fungsi untuk menghitung jumlah hari dari 1/1/0001 ke tanggal tertentu
long long daysFromBeginning(int day, int month, int year) {
    long long total = 0;
    
    // Menambahkan jumlah hari dari tahun-tahun sebelumnya
    for (int j = 1; j < year; j++) {
        total += isLeapYear(j) ? 366 : 365;
    }

    // Menambahkan jumlah hari dari bulan-bulan sebelumnya dalam tahun berjalan
    for (int i = 1; i < month; i++) {
        total += getDaysInMonth(i, year);
    }

    // Menambahkan jumlah hari dari bulan berjalan
    total += day;
    
    return total;
}

int main() {
    int d1, m1, y1, d2, m2, y2;
    
    // Input tanggal pertama
    scanf("%d %d %d", &d1, &m1, &y1);
    while (!isValidDate(d1, m1, y1)) {
        printf("Tanggal tidak valid\n");
        scanf("%d %d %d", &d1, &m1, &y1);
    }

    // Input tanggal kedua
    scanf("%d %d %d", &d2, &m2, &y2);
    while (!isValidDate(d2, m2, y2)) {
        printf("Tanggal tidak valid\n");
        scanf("%d %d %d", &d2, &m2, &y2);
    }

    // Memastikan tanggal kedua lebih besar dari tanggal pertama
    while (y2 < y1 || (y2 == y1 && m2 < m1) || (y2 == y1 && m2 == m1 && d2 < d1)) {
        printf("Tanggal kedua lebih dulu\n");
        scanf("%d %d %d", &d2, &m2, &y2);
        while (!isValidDate(d2, m2, y2)) {
            printf("Tanggal tidak valid\n");
            scanf("%d %d %d", &d2, &m2, &y2);
        }
    }

    // Menghitung selisih hari
    long long diff = daysFromBeginning(d2, m2, y2) - daysFromBeginning(d1, m1, y1);
    printf("%lld\n", diff);

    return 0;
}
