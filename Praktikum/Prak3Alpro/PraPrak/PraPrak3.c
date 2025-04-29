#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int calculate_score(int arr[], int n) {
    if (n == 0) return 0;
    if (n == 1) return arr[0] * arr[0];

    int fpb = arr[0], kpk = arr[0];
    for (int i = 1; i < n; i++) {
        fpb = gcd(fpb, arr[i]);
        kpk = lcm(kpk, arr[i]);
    }
    return fpb * kpk;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int max_score = calculate_score(arr, N);

    for (int i = 0; i < N; i++) {
        int temp_arr[N - 1], k = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                temp_arr[k++] = arr[j];
            }
        }
        int new_score = calculate_score(temp_arr, N - 1);
        if (new_score > max_score) {
            max_score = new_score;
        }
    }

    printf("%d\n", max_score);
    return 0;
}
