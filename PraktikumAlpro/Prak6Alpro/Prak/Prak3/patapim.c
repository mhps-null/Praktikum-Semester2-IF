#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "Boolean.h"

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    ListDin L;
    int N;
    scanf("%d", &N);
    CreateListDin(&L, N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &L.buffer[i]);
    }
    L.nEff = N;

    int min = L.buffer[0];
    for (int i = 1; i < N; i++) {
        if (L.buffer[i] < min) {
            min = L.buffer[i];
        }
    }

    int gcd = 0;
    for (int i = 0; i < N; i++) {
        if (L.buffer[i] != min) {
            int diff = L.buffer[i] - min;
            gcd = (gcd == 0) ? diff : GCD(gcd, diff);
        }
    }

    printf("%d\n", gcd);
    return 0;
}