#include <stdio.h>

char* sifat(int baik,int buruk);

int main(){
    
    int baik,buruk;
    printf("Apa sifatmu?");
    scanf("%d %d", &baik, &buruk);
    printf("Sifatmu adalah %s", sifat(baik,buruk));


    return 0;
    
}

char* sifat(int baik,int buruk){
    return baik>buruk ? "Baik":"Buruk";
}