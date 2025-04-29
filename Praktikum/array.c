#include <stdio.h>

int main() {
    char arr[4][100];  // 4 string, masing-masing bisa menampung hingga 99 karakter + '\0'

    for (int i = 0; i < 3; i++) {
        scanf("%99s", arr[i]);  // Hindari buffer overflow dengan membatasi panjang input
    }

    printf("%s %s %s\n", arr[0], arr[1], arr[2]);  // Menampilkan 3 string pertama

    return 0;
}
