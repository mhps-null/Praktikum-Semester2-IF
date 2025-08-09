#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int nums[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }

    int target;
    scanf("%d", &target);

    int found = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (nums[i] + nums[j] == target) {
                printf("[%d, %d]\n", i, j);
                found = 1;
                break; // Hentikan loop setelah menemukan solusi
            }
        }
        if (found) {
            break; // Hentikan loop setelah menemukan solusi
        }
    }

    return 0;
}