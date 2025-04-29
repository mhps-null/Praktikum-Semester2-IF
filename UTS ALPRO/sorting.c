#include <stdio.h>


int main(){
    int arr[8]={9,1,8,2,7,3,1,9};

    // selection sort
    // for(int i = 0;i<8;i++){
    //     for(int j =i;j<8;j++){
    //         if (arr[i]<arr[j]){
                // int temp = arr[i];
                // arr[i]=arr[j];
                // arr[j]=temp;
    //         }
    //     }
    // }

    // bubble sort standar
    // for(int i =0;i<=7-1;i++){
    //     for(int j=7;j>=i+1;j--){
    //         if(arr[j]<arr[j-1]){
    //             int temp = arr[j];
    //             arr[j]=arr[j-1];
    //             arr[j-1]=temp;
    //         }
    //     }
    // }

    printf("[");
    for(int k=0;k<8;k++){
        if(k==7){
            printf("%d",arr[k]);
        }else{printf("%d, ",arr[k]);}
        
    }printf("]\n");

    return 0;
}