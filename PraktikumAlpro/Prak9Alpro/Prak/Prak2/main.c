#include <stdio.h>
#include "queue.h" 

int main(){
    Queue q;int N;
    CreateQueue(&q);
    scanf("%d",&N);
    int sort[N];
    for (int i=0;i<N;i++){
        scanf("%d",&sort[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(sort[j] > sort[i]){
                int temp = sort[j];
                sort[j]=sort[i];
                sort[i]=temp;
            }
        }
    }
    for(int i=0;i<N;i++){
        enqueue(&q,sort[i]);
    }
    displayQueue(q);
    return 0;
}