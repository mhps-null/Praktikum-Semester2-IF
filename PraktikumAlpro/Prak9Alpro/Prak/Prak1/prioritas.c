#include "queue.h"
#include <stdio.h>

void prioritizeValue(Queue *q, int x){
    int n = length(*q);
    ElType p[n];
    for(int i = 0; i < n; i++){
        ElType v;
        dequeue(q, &v);
        p[i] = v;
    }
    for(int i = 0; i < n; i++){
        if(p[i] == x){
            enqueue(q, x);
        }
    }
    for(int i = 0; i < n; i++){
        if(p[i] != x){
            enqueue(q, p[i]);
        }
    }

}


