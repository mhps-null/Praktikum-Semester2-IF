#include <stdio.h>
#include <stdlib.h>
#include "listkontigu.h"
#include "Boolean.h"        
int main() {
    ListKontigu l;
    CreateList(&l);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int val;
        scanf("%d",&val);
        if(i==0){
            insertFirst(&l,val);
        }else{
            insertLast(&l,val);

            for(int j=0;j<i+1;j++){
                if(l.contents[j]>l.contents[i]){
                    int temp = l.contents[j];
                    l.contents[j]=l.contents[i];
                    l.contents[i]=temp;
                    
                }
            }
        }
        printList(l);printf("\n");
    }
    return 0;
}
