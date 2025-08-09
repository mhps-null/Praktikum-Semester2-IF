#include <stdio.h>
#include "stack.h"

int main() {
    int N;
    scanf("%d", &N);

    int w[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &w[i]);
    }

    Stack S;
    CreateEmpty(&S);

    long long total = 0;

    for (int L = 0; L < N; L++) {
        for (int R = L; R < N; R++) {
            CreateEmpty(&S);  // kosongkan stack untuk kelompok baru

            // Masukkan elemen ke stack
            for (int i = L; i <= R; i++) {
                Push(&S, w[i]);
            }

            // Cari maksimum di stack
            int maxVal = InfoTop(S);
            Stack tempS = S;

            while (!IsEmpty(tempS)) {
                int val;
                Pop(&tempS, &val);
                if (val > maxVal) {
                    maxVal = val;
                }
            }

            total += maxVal;
        }
    }

    printf("%lld\n", total);

    return 0;
}
