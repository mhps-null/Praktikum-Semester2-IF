#include "liststatik.h"

int main(){
    ListStatik L;
    readList(&L);
    insertAt(&L,5,3);
    printList(L);
}