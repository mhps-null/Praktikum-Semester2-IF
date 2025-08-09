#include <stdio.h>
#include "listkontigu.h"

int main() {
    ListKontigu l1, l2, l3;
    ElType val;

    // Create list kosong
    CreateList(&l1);
    CreateList(&l2);
    readList(&l1);
    readList(&l2);
    printList(l1);
    printList(l2);
    return 0;
}
