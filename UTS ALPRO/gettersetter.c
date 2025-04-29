#include <stdio.h>

typedef struct {
    int umur;
} Orang;

int getUmur(Orang o) {
    return o.umur;
}

void setUmur(Orang *o, int umurBaru) {
    o->umur = umurBaru;
}

int main(){
    Orang aku;
    setUmur(&aku, 20);                  // Setter
    printf("Umurku: %d\n", getUmur(aku)); // Getter
    return 0;
}