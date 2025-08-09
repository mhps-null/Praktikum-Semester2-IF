#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "ui.h"

void dealokasiList(List *l) {
    /* I.S. l terdefinisi, mungkin kosong */
    /* F.S. Semua elemen list di-dealokasi. *l menjadi NULL */
    
    while (!isEmpty(*l)) {
        ElType temp;
        deleteFirst(l, &temp);
    }
}

void insertSorted(List *l, ElType val) {
    /* I.S. l terdefinisi, mungkin kosong */
    /* F.S. val sudah ada di dalam l dengan semua elemen l terurut membesar */
    
    // Jika list kosong atau val lebih kecil dari elemen pertama
    if (isEmpty(*l) || val < INFO(*l)) {
        insertFirst(l, val);
        return;
    }
    
    // Cari posisi yang tepat untuk insert
    Address current = *l;
    int idx = 0;
    
    while (current != NULL && INFO(current) < val) {
        current = NEXT(current);
        idx++;
    }
    
    // Insert di posisi yang tepat
    insertAt(l, val, idx);
}

List getUnion(List l1, List l2) {
    /* I.S. l1 dan l2 terdefinisi, mungkin kosong */
    /* F.S. l1 dan l2 tetap, tidak berubah */
    /* Mengembalikan list yang merupakan hasil union antara l1 dan l2 */
    
    List result;
    CreateList(&result);
    Address current;
    
    // Tambahkan semua elemen dari l1
    current = l1;
    while (current != NULL) {
        // Cek apakah elemen sudah ada di result (untuk menghindari duplikasi)
        if (indexOf(result, INFO(current)) == IDX_UNDEF) {
            insertSorted(&result, INFO(current));
        }
        current = NEXT(current);
    }
    
    // Tambahkan semua elemen dari l2 yang belum ada di result
    current = l2;
    while (current != NULL) {
        if (indexOf(result, INFO(current)) == IDX_UNDEF) {
            insertSorted(&result, INFO(current));
        }
        current = NEXT(current);
    }
    
    return result;
}

List getIntersect(List l1, List l2) {
    /* I.S. l1 dan l2 terdefinisi, mungkin kosong */
    /* F.S. l1 dan l2 tetap, tidak berubah */
    /* Mengembalikan list yang merupakan hasil intersect antara l1 dan l2 */
    
    List result;
    CreateList(&result);
    Address current;
    
    // Cari elemen yang ada di kedua list
    current = l1;
    while (current != NULL) {
        // Jika elemen ada di l2 dan belum ada di result
        if (indexOf(l2, INFO(current)) != IDX_UNDEF && 
            indexOf(result, INFO(current)) == IDX_UNDEF) {
            insertSorted(&result, INFO(current));
        }
        current = NEXT(current);
    }
    
    return result;
}

void getData(List *Union, List *Irisan) {
    /* I.S. Union dan Irisan terdefinisi dengan elemen awal kosong */
    /* F.S. Union dan Irisan berisi hasil union dan intersect seluruh data yang diinputkan */
    
    int n; // jumlah hari
    scanf("%d", &n);
    
    if (n == 0) {
        CreateList(Union);
        CreateList(Irisan);
        return;
    }
    
    List *hariList = (List*)malloc(n * sizeof(List));
    
    // Input data untuk setiap hari
    for (int i = 0; i < n; i++) {
        CreateList(&hariList[i]);
        
        int x; // jumlah nimons pada hari ke-i
        scanf("%d", &x);
        
        for (int j = 0; j < x; j++) {
            ElType nimon;
            scanf("%d", &nimon);
            insertLast(&hariList[i], nimon);
        }
    }
    
    // Inisialisasi Union dengan hari pertama
    *Union = getUnion(hariList[0], hariList[0]); // Copy hari pertama
    
    // Inisialisasi Irisan dengan hari pertama
    *Irisan = getIntersect(hariList[0], hariList[0]); // Copy hari pertama
    
    // Proses hari ke-2 sampai ke-n
    for (int i = 1; i < n; i++) {
        // Update Union
        List tempUnion = getUnion(*Union, hariList[i]);
        dealokasiList(Union);
        *Union = tempUnion;
        
        // Update Irisan
        List tempIrisan = getIntersect(*Irisan, hariList[i]);
        dealokasiList(Irisan);
        *Irisan = tempIrisan;
    }
    
    // Dealokasi memory untuk hariList
    for (int i = 0; i < n; i++) {
        dealokasiList(&hariList[i]);
    }
    free(hariList);
}