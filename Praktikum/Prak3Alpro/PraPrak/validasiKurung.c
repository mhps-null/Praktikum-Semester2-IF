#include <stdio.h>
#include <string.h>

#define MAX 100

// Fungsi untuk mengecek apakah dua karakter adalah pasangan tanda kurung
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Fungsi utama untuk mengecek validitas tanda kurung
int isValidParentheses(char *str) {
    char stack[MAX];  // Stack untuk menyimpan tanda kurung pembuka
    int top = -1;     // Pointer stack (top)

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        // Jika karakter adalah tanda kurung pembuka, push ke stack
        if (ch == '(' || ch == '[' || ch == '{') {
            if (top == MAX - 1) return 0;  // Stack overflow (tidak akan terjadi dalam kasus ini)
            stack[++top] = ch;  // Push elemen ke stack
        }
        // Jika karakter adalah tanda kurung penutup
        else if (ch == ')' || ch == ']' || ch == '}') {
            // Jika stack kosong, tidak ada pasangan tanda kurung pembuka
            if (top == -1) return 0;

            // Cek apakah pasangan tanda kurung cocok
            if (!isMatchingPair(stack[top], ch)) return 0;

            // Jika cocok, pop stack (hapus elemen terakhir)
            top--;
        }
    }

    // Jika stack kosong di akhir, berarti tanda kurung valid
    return (top == -1);
}

int main() {
    char str[MAX];
    fgets(str, sizeof(str), stdin); // Input string dari user

    // Hapus karakter newline dari fgets
    str[strcspn(str, "\n")] = 0;

    if (isValidParentheses(str)) {
        printf("valid\n");
    } else {
        printf("Tidak valid\n");
    }

    return 0;
}
