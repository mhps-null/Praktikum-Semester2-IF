#include <stdio.h>


void arrbaru(int arr[], int barRot, int N) {
    int temp[N];

   
    barRot = barRot % N;

    
    for (int i = 0; i < N; i++) {
        temp[(i + barRot) % N] = arr[i];
    }

   
    printf("[");
    for (int i = 0; i < N; i++) {
        printf("%d", temp[i]);
        if (i < N - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int N, jrot;

    
    scanf("%d", &N);

   
    scanf("%d", &jrot);

    int arr[N], barRot[jrot];

   
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }


    for (int j = 0; j < jrot; j++) {
        scanf("%d", &barRot[j]);
    }

  
    for (int h = 0; h < jrot; h++) {
        arrbaru(arr, barRot[h], N);
    }

    return 0;
}
