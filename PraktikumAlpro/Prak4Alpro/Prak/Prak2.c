#include <stdio.h>
#include "tester.h" // Comment this when developing in local
int main () {
    init(); // Comment this when developing in local
    FILE *inputFile, *outputFile;
    inputFile=fopen("file_a.txt","r");

    int ID1,pisang1;int pisang[1001]={0};

    while(fscanf(inputFile,"%d %d",&ID1,&pisang1)==2){
        if (ID1 == -1 && pisang1==99) break;
        pisang[ID1]=pisang1;
    }

    fclose(inputFile);   
    inputFile=fopen("file_b.txt","r"); 
    while(fscanf(inputFile,"%d %d",&ID1,&pisang1)==2){
        if (ID1 == -1 && pisang1==99) break;
        pisang[ID1]=pisang1;
    }

    for(int i=1;i<1001;i++){
        if(pisang[i]!=0){
            printf("%d %d\n",i,pisang[i]);
        }
        
    }
        

    fclose(inputFile);
    return 0;
}