#include "listlinier.h"
#include <stdio.h>
#include "ui.h"

int main(){
    List *Union,*Irisan;
    CreateList(Union);CreateList(Irisan);
    getData(Union,Irisan);
    displayList(*Union);
    displayList(*Irisan);
}