#include <stdio.h>

int main(){
    for(int i = 1; i<=10; i++){
        i=i+i+i;
        printf("The value of i is %d\n", i);
    }
}