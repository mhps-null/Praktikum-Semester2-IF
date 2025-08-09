#include <stdio.h>


int binarySearch(int list[], long N, int target) {
    long left=0, right=N-1;
    while (left<=right) {
        long mid=left+(right-left)/2;
        if (list[mid]==target) {
            return mid; 
        } else if (list[mid]<target){
            left=mid+1; 
        } else {
            right=mid-1; 
        }
    }
    return -1; 
}

int main() {
    long N, Q;
    int list[100000]; 
    int indeks[100];  

    
    scanf("%ld", &N);
    for (long i = 0; i < N; i++) {
        scanf("%d", &list[i]);
    }

   
    scanf("%ld", &Q);
    
    for (long i = 0; i < Q; i++) {
        int target;
        scanf("%d", &target);
        indeks[i] = binarySearch(list, N, target); 
    }

   
    printf("[");
    for (int i = 0; i < Q; i++) {
        if (i > 0) printf(", "); 
        printf("%d", indeks[i]); 
    }
    printf("]\n"); 

    return 0;
}
