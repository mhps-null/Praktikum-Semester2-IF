#include <stdio.h>

int main() {
    int N, geser, arr[10000], temp[10000];

    scanf("%d %d", &N, &geser);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        temp[i] = arr[(i + geser - 1) % N]; 
    }

    for (int i = 0; i < N; i++) {
        if(i==N-1){printf("%d\n", temp[i]);}
        else{printf("%d ", temp[i]);}
    }


    return 0;
}
