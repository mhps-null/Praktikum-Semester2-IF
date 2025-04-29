#include <stdio.h>


int main(){
    long N; signed long long angka[10000],target;long long indeks[2];
    scanf("%ld",&N);

    for(long long i=0;i<N;i++){
        scanf("%lld",&angka[i]); 
    }
    
    scanf("%lld",&target);

    for (long long j=0;j<N;j++){
        for(long long k=j+1;k<N;k++){
            if (angka[j]>angka[k]){
                continue;}
            else{
                if (angka[j]+angka[k]==target){
                    printf("[");
                    printf("%lld, %lld",j,k);
                    printf("]\n");
                    break;
                }
            }

        }
    }

    return 0;
}