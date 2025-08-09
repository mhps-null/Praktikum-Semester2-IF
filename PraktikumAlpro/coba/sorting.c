#include <stdio.h>


int main(){
    int arr[8]={9,1,8,2,7,3,1,9};
    
    // for(int i = 0;i<8;i++){
    //     for(int j =i;j<8;j++){
    //         if (arr[i]<arr[j]){
                // int temp = arr[i];
                // arr[i]=arr[j];
                // arr[j]=temp;
    //         }
    //     }
    // }

    for(int i =0;i<=7-1;i++){
        for(int j=7;j>=i+1;j--){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    
    for(int k=0;k<8;k++){
        printf("%d\n",arr[k]);
    }

    return 0;
}