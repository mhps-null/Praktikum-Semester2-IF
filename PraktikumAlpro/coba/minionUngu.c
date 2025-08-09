#include <stdio.h>

int main(){
    int N,T,X;long long int pelipat;long long int virus;
    
    scanf("%d",&N);
    scanf("%d",&T);
    scanf("%d",&X);
    virus=N;pelipat=N*X;
    long long int j=0;
    for (int i=0;i<T;i++){
        virus += pelipat;
        pelipat*=X;
        j+=1;
    }
    printf("Terdapat %lld Virus Nimons Gila pada jam ke-%lld\n",virus,j);
    return 0;
}