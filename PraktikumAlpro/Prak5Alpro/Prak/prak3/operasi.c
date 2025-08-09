#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "operasi.h"

/* --- Konstruktor --- */
Vital MakeVital(int tekanan, int detak, float saturasi){
    if (saturasi>=0 && saturasi<=100){
        Vital vital;
        vital.detakJantung=detak;
        vital.tekananDarah=tekanan;
        vital.saturasiOksigen=saturasi;
        return vital;
    }
    
}
Lokasi MakeLokasi(int x, int y){
    Lokasi lokasi;
    lokasi.x=x;lokasi.y=y;
    return lokasi;
}
Pasien MakePasien(char nama[], Vital v, Lokasi l){
    Pasien pasien;
    strcpy(pasien.nama,nama);
    pasien.v=v;pasien.l=l;
    return pasien;
}

/* --- Aksesor --- */
int GetTekanan(Vital v){
    return v.tekananDarah;
}
int GetDetak(Vital v){
    return v.detakJantung;
}
float GetSaturasi(Vital v){
    return v.saturasiOksigen;
}
int GetX(Lokasi l){
    return l.x;
}
int GetY(Lokasi l){
    return l.y;
}
Vital GetVital(Pasien p){
    return p.v;
}
Lokasi GetLokasi(Pasien p){
    return p.l;
}

/* --- Mutator --- */
void SetTekanan(Vital *v, int tekanan){
    v->tekananDarah=tekanan;
}
void SetDetak(Vital *v, int detak){
    v->detakJantung=detak;
}
void SetSaturasi(Vital *v, float saturasi){
    v->saturasiOksigen=saturasi;
}
void SetX(Lokasi *l, int x){
    l->x=x;
}
void SetY(Lokasi *l, int y){
    l->y=y;
}
void SetVital(Pasien *p, Vital v){
    p->v=v;
}
void SetLokasi(Pasien *p, Lokasi l){
    p->l=l;
}

/* --- Operasi Vital --- */
bool IsSehat(Vital v){
    if(v.detakJantung>=60 && v.detakJantung<=100 && v.tekananDarah>=90 && v.tekananDarah<=140
    && v.saturasiOksigen>=95.0){
        return true;
    }else{return false;}
}
/* True jika:
   90 <= tekanan darah <= 140
   60 <= detak jantung <= 100
   saturasi >= 95.0 */

void ResetVital(Vital *v){
    v->detakJantung=80;
    v->saturasiOksigen=98.0;
    v->tekananDarah=120;
}
/* Mengatur kembali semua nilai vital ke default (120/80/98.0) */

int CompareVital(Vital a, Vital b){
    if((a.detakJantung+a.saturasiOksigen+a.tekananDarah)>
    (b.detakJantung+b.saturasiOksigen+b.tekananDarah)){
        return 1;
    }else if ((a.detakJantung+a.saturasiOksigen+a.tekananDarah)==
    (b.detakJantung+b.saturasiOksigen+b.tekananDarah))
    {
        return 0;
    }else{return -1;}
    
}
/* Mengembalikan:
   -1 jika a < b (tekanan + detak + saturasi total)
    0 jika sama
    1 jika a > b
*/

/* --- Operasi Lokasi --- */
void PindahPasien(Lokasi *l, int dx, int dy){
    l->x+=dx;l->y+=dy;
}
/* Memindahkan pasien ke koordinat baru berdasarkan delta */

/* --- Print --- */
void PrintVital(Vital v){
    printf("Tekanan: %d mmHg, Detak: %d bpm, Saturasi: %.2f%%\n",
    v.tekananDarah,v.detakJantung,v.saturasiOksigen);
}
/* Format: "Tekanan: xxx mmHg, Detak: xxx bpm, Saturasi: xx.xx%" */

void PrintLokasi(Lokasi l){
    printf("Lokasi: (%d, %d)\n",l.x,l.y);
}
/* Format: "Lokasi: (x, y)" */

void PrintPasien(Pasien p){
    printf("Nama: %s\n",p.nama);
    PrintVital(p.v);
    PrintLokasi(p.l);
}
/* Menampilkan semua info pasien:
   Nama
   Vital
   Lokasi
*/