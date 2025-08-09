#include <stdio.h>
#include "listkontigu.h"

int main() {
    int n;
    ListKontigu l;
    CreateList(&l);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ELMT(l, i));
    }

    int sorted = 1;
    for (int i = 0; i < n - 1; i++) {
        if (ELMT(l, i) > ELMT(l, i + 1)) {
            sorted = 0;
            break;
        }
    }

    if (sorted) {
        printf("YA\n");
        return 0;
    }

    int l_index = -1, r_index = -1;
    for (int i = 0; i < n - 1; i++) {
        if (ELMT(l, i) > ELMT(l, i + 1)) {
            l_index = i;
            break;
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (ELMT(l, i - 1) > ELMT(l, i)) {
            r_index = i;
            break;
        }
    }

    int left = l_index, right = r_index;
    while (left < right) {
        int temp = ELMT(l, left);
        ELMT(l, left) = ELMT(l, right);
        ELMT(l, right) = temp;
        left++;
        right--;
    }

    sorted = 1;
    for (int i = 0; i < n - 1; i++) {
        if (ELMT(l, i) > ELMT(l, i + 1)) {
            sorted = 0;
            break;
        }
    }

    if (sorted) {
        printf("YA\n");
        printf("%d %d\n", l_index, r_index);
    } else {
        printf("TIDAK\n");
    }

    return 0;
}
