#include <stdio.h>
#include "prioritas.h"

void prioritizeValue(Queue *q, int x) {
    if (isEmpty(*q)) return;

    Queue temp;
    CreateQueue(&temp);
    Queue nonPriority;
    CreateQueue(&nonPriority);

    int val;

    while (!isEmpty(*q)) {
        dequeue(q, &val);
        if (val == x) {
            enqueue(&temp, val);        
        } else {
            enqueue(&nonPriority, val);
        }
    }

    while (!isEmpty(temp)) {
        dequeue(&temp, &val);
        enqueue(q, val);
    }

    while (!isEmpty(nonPriority)) {
        dequeue(&nonPriority, &val);
        enqueue(q, val);
    }
}