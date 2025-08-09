#include <stdio.h>
#include "queue.h"
#include "stack.h"

void selectionSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            int temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    int creditScores[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &creditScores[i]);
    }

    // Sort descending
    selectionSortDesc(creditScores, N);

    Queue resultQueue;
    CreateQueue(&resultQueue);
    for (int i = 0; i < N; i++) {
        enqueue(&resultQueue, creditScores[i]);
    }

    displayQueue(resultQueue);
    return 0;
}
