#include <stdio.h>
int binary_search_first(int arr[],int left,int right,int target){
    int result=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if (target<=arr[mid]){
            if(target==arr[mid]) result=mid;
            right=mid-1;
            
        }else{left=mid+1;}

    }
    return result;
}

int main() {
    int N,angka[100001],Q,index[100001];
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d",&angka[i]);
    }

    scanf("%d",&Q);
    for(int i = 0;i<Q;i++){
        int target;
        scanf("%d", &target);
        
        index[i] = binary_search_first(angka,0,N-1,target);
        
    }
    printf("[");
    for(int i = 0;i<Q;i++){
        if(i==Q-1){printf("%d", index[i]);}
        else{printf("%d, ", index[i]);}
    }
    printf("]\n");
    return 0;
}