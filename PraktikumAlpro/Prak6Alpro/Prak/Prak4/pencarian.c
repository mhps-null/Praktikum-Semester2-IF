#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
// #include "Boolean.h"

#define NIMONS 5

char *names[NIMONS] = {"Kebin", "Stewart", "Pop", "Luiy", "Toto"};

int main() {
    int N;
    scanf("%d", &N);

    ListDin L[NIMONS]; 

    for (int i = 0; i < NIMONS; i++) {
        CreateListDin(&L[i], N);
    }

    for (int race = 0; race < N; race++) {
        for (int i = 0; i < NIMONS; i++) {
            int waktu;
            scanf("%d", &waktu);
            L[i].buffer[race] = waktu;
        }
    }
    for (int i = 0; i < NIMONS; i++) {
        L[i].nEff = N;
    }

    double peningkatan[NIMONS];
    for (int i = 0; i < NIMONS; i++) {
        int sum = 0;
        for (int j = 1; j < N; j++) {
            sum += L[i].buffer[j] - L[i].buffer[j-1];
        }
        peningkatan[i] = (double)sum / (N - 1);
    }

    int terbaik = 0;
    for (int i = 1; i < NIMONS; i++) {
        if (peningkatan[i] < peningkatan[terbaik]) {
            terbaik = i;
        }
    }

    printf("%s\n", names[terbaik]);
    return 0;
}
