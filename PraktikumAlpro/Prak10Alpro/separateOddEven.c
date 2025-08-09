#include "listlinier.h"
#include "stdio.h"

void separateOddEven(List *l)
{
    /* I.S. l terdefinisi, mungkin kosong */
    /* F.S. List l diatur ulang sehingga semua bilangan ganjil muncul sebelum bilangan genap */
    /*      dengan mempertahankan urutan relatif dalam setiap kelompok */
    
    if (isEmpty(*l) || NEXT(*l) == NULL) {
        return;
    }
    
    List oddList = NULL;
    List evenList = NULL;
    
    Address current = *l;
    
    while (current != NULL) {
        if (INFO(current) % 2 == 1) {
            insertLast(&oddList, INFO(current));
        } else {
            insertLast(&evenList, INFO(current));
        }
        current = NEXT(current);
    }
    
    while (!isEmpty(*l)) {
        ElType temp;
        deleteFirst(l, &temp);
    }
    
    current = oddList;
    while (current != NULL) {
        insertLast(l, INFO(current));
        current = NEXT(current);
    }
    
    current = evenList;
    while (current != NULL) {
        insertLast(l, INFO(current));
        current = NEXT(current);
    }
    
    while (!isEmpty(oddList)) {
        ElType temp;
        deleteFirst(&oddList, &temp);
    }
    
    while (!isEmpty(evenList)) {
        ElType temp;
        deleteFirst(&evenList, &temp);
    }
}