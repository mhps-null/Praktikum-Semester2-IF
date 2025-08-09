
#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"
#define boolean unsigned char
#define true 1
#define false 0

int main (){
    ListStatik L;
    CreateListStatik(&L);
    int perintah;
    scanf("%d",&perintah);
    do{
        int elmt,idx;
        if(perintah==1){
            scanf("%d %d",&elmt,&idx);
            if(idx >= 0 && idx <= listLength(L) && isFull(L)==false){
                insertAt(&L,elmt,idx);   
            }else{
                printf("Aw, gabisa ngelakuin aksi itu\n");
            }
            printList(L);
            printf("\n");
        }else if(perintah==0){
            scanf("%d",&idx);
            if(isIdxEff(L,idx)==true && isEmpty(L)==false){
                deleteAt(&L,&elmt,idx);  
            }else{
                printf("Aw, gabisa ngelakuin aksi itu\n");
            }
            printList(L);
            printf("\n");
        }
        scanf("%d",&perintah);
    }while(perintah!=-1);
}