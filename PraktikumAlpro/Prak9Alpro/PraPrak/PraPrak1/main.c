#include <stdio.h>
#include "queue.h" // pastikan ini mengarah ke file queue.h kamu

int main() {
    Queue q;
    ElType val;

    // Test: CreateQueue
    CreateQueue(&q);
    printf("Setelah CreateQueue:\n");
    displayQueue(q); // harusnya: []

    // Test: isEmpty
    printf("Apakah kosong? %s\n", isEmpty(q) ? "YA" : "TIDAK");

    // Test: enqueue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Setelah enqueue 10, 20, 30:\n");
    displayQueue(q); // harusnya: [10,20,30]

    // Test: isEmpty dan isFull
    printf("Apakah kosong? %s\n", isEmpty(q) ? "YA" : "TIDAK");
    printf("Apakah penuh? %s\n", isFull(q) ? "YA" : "TIDAK");

    // Test: length
    printf("Banyak elemen: %d\n", length(q)); // harusnya 3

    // Test: dequeue
    dequeue(&q, &val);
    printf("Setelah dequeue, elemen dikeluarkan: %d\n", val); // harusnya 10
    displayQueue(q); // harusnya: [20,30]

    // Tambahkan hingga penuh (opsional)
    for (int i = 0; i < CAPACITY - 2; i++) {
        enqueue(&q, i);
    }
    printf("Setelah enqueue hingga penuh:\n");
    displayQueue(q);
    printf("Apakah penuh? %s\n", isFull(q) ? "YA" : "TIDAK");

    // Coba enqueue saat penuh
    enqueue(&q, 999); // ini seharusnya tidak ditambahkan
    printf("Setelah mencoba enqueue 999 ke queue penuh:\n");
    displayQueue(q);

    // Dequeue semua elemen
    printf("Mengosongkan queue:\n");
    while (!isEmpty(q)) {
        dequeue(&q, &val);
        printf("Dequeued: %d\n", val);
    }
    displayQueue(q);
    printf("Apakah kosong? %s\n", isEmpty(q) ? "YA" : "TIDAK");

    return 0;
}
