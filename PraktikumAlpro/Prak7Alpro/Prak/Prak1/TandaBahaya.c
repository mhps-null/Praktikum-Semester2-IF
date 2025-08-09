#include <stdio.h>
#include <stdlib.h>
#include "listkontigu.h"

int main() {
    int n;
    ListKontigu l;
    int ada=0;
    CreateList(&l);
    do{
        scanf("%d", &n);
    }while(n<0 || n>CAPACITY);

    for(int i=0; i<n; i++){
        scanf("%d", &ELMT(l, i));
    }

    for(int i=0; i<n-2; i++){
        if(ELMT(l, i)<ELMT(l, i+2) && ELMT (l, i+1)> ELMT(l, i+2)){
            ada=1;
        };
    }

    if(ada){
        printf("Nyalakan\n");
    }
    else{
        printf("Santai\n");
    }
    return 0;
}
