#include <stdio.h>


int main(){
    int N;
    scanf("%d",&N);

    int geser,angka[10001];
    scanf("%d",&geser);
    geser = geser % N;
    for(int i = 0;i<N;i++){
        scanf("%d",&angka[i]);
    }

    for(int i = 0;i<geser;i++){
        int last=angka[N-1];

        for(int j = N-1;j>0;j--){
            angka[j]=angka[j-1];
        }

        angka[0]=last;
        
    }

    for(int i = 0;i<N;i++){
        if (i==N-1){
            printf("%d\n",angka[i]);
        }else{printf("%d ",angka[i]);}
        
    }

    return 0;
}