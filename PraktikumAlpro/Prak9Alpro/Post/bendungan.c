#include <stdio.h>
#include "stack.h"

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    Stack S;
    CreateEmpty(&S);
    int total = 0, i = 0;

    while (i < N) {
        if (IsEmpty(S) || A[i] <= A[InfoTop(S)]) {
            Push(&S, i);
            i++;
        } else {
            int top;
            Pop(&S, &top);

            if (IsEmpty(S)) continue;

            int distance = i - InfoTop(S) - 1;
            int bounded_height = (A[i] < A[InfoTop(S)] ? A[i] : A[InfoTop(S)]) - A[top];
            if (bounded_height > 0) {
                total += distance * bounded_height;
            }
        }
    }

    printf("%d\n", total);
    return 0;
}
