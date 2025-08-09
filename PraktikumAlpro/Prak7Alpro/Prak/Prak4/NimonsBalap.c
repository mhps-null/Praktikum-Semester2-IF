#include <stdio.h>
#include <stdlib.h>
#include "listkontigu.h"
#include "Boolean.h"
int main() {
    ListKontigu L,max;
    CreateList(&L);CreateList(&max);
    readList(&L);
    int N;
    scanf("%d",&N);

    for (int i=0;i<listLength(L)-N+1;i++){
        max.contents[i]=L.contents[i];
        for(int j=i;j<i+N;j++){
            if(L.contents[j]>max.contents[i]){
                max.contents[i]=L.contents[j];
            }
        }
    }

    printList(max);printf("\n");
    return 0;
}
