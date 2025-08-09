#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"
// #include "Boolean.h"
#define boolean unsigned char
#define TRUE 1
#define FALSE 0

int main(){
    ListStatik l1,l2;
    CreateListStatik(&l1);CreateListStatik(&l2);
    readList(&l1);
    readList(&l2);
    
    int len1 = listLength(l1);
    int len2 = listLength(l2);
    for(int j = 0; j < len2; j++) {
        insertAt(&l1, l2.contents[j], len1 + j);
    }
    sortList(&l1, 1);
    printList(l1);
    printf("\n");
}