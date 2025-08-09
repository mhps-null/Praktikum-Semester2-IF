#include "liststatik.h"

#include <stdio.h>
#include <stdlib.h>

#define boolean unsigned char
#define true 1
#define false 0


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
   for(int i=0;i<CAPACITY;i++){l->contents[i]=MARK;}
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
   int i=0,nEff=0; 
   while(i<CAPACITY){
      if(l.contents[i]!=MARK){nEff++;}
      i++;
   }
   return nEff;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
   int i=0; boolean found=false; 
   while(i<CAPACITY && !found){
      if(l.contents[i]!=MARK){found=true;}
      i++;
   }
   i-=1;
   return i;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l){
   int i=0;int idx; 
   while(i<CAPACITY){
      if(l.contents[i]!=MARK){idx=i;}
      i++;
   }
   return idx;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
   return (i<CAPACITY && i>=0);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean isIdxEff(ListStatik l, IdxType i){
   return (i>=0 && i<listLength(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
   return (listLength(l)==0);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatik l){
   return (listLength(l)==CAPACITY);
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
   int N; CreateListStatik(l);
   do{
      scanf("%d",&N);
   }while(N<0 || N>CAPACITY);
   for(int i=0;i<N;i++){
      scanf("%d",&l->contents[i]);
   }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */

void printList(ListStatik l){
   printf("[");
   for(int i=0;i<listLength(l);i++){
      if(i==listLength(l)-1){
         printf("%d",l.contents[i]);
      }
      else{printf("%d,",l.contents[i]);}
   }
   printf("]");
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
   ListStatik lbaru;
   CreateListStatik(&lbaru);
   if(plus){
      for(int i=0;i<listLength(l1);i++){
         lbaru.contents[i]=l1.contents[i]+l2.contents[i];
      }
   }else{
      for(int i=0;i<listLength(l1);i++){
         lbaru.contents[i]=l1.contents[i]-l2.contents[i];
      }
   }
   return lbaru;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
   if(listLength(l1)==listLength(l2)){
      for(int i=0;i<listLength(l1);i++){
         if(l1.contents[i]!=l2.contents[i]){return false;}
      }
      return true;
   }else{
      return false;
   }
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
   for(int i=0;i<listLength(l);i++){
      if(l.contents[i]==val){return i;}
   }
   return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
   *max = l.contents[0]; *min=l.contents[0];
   for(int i=1;i<listLength(l);i++){
      if(l.contents[i]>*max){*max=l.contents[i];}
      if(l.contents[i]<*min){*min=l.contents[i];}
   }
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
   for(int i=listLength(*l);i>=1;i--){
      l->contents[i]=l->contents[i-1];
   }
   l->contents[0]=val;
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */

/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
   for(int i=listLength(*l);i>=idx+1;i--){
      l->contents[i]=l->contents[i-1];
   }
   l->contents[idx]=val;
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */

/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val){
   l->contents[listLength(*l)]=val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
   int len = listLength(*l);
   *val=l->contents[0];
   for(int i=1;i<listLength(*l);i++){
      l->contents[i-1]=l->contents[i];
   }
   l->contents[len-1]=MARK;
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
   int len = listLength(*l);
   *val=l->contents[idx];
   for(int i=idx+1;i<listLength(*l);i++){
      l->contents[i-1]=l->contents[i];
   }
   l->contents[len-1]=MARK;
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
   *val=l->contents[getLastIdx(*l)];
   l->contents[getLastIdx(*l)]=MARK;
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
   if(asc){
      for(int i=0;i<listLength(*l);i++){
         for(int j=i+1;j<listLength(*l);j++){
            if(l->contents[i]>l->contents[j]){
               int temp = l->contents[j];
               l->contents[j]=l->contents[i];
               l->contents[i]=temp;
            }
         }
      }
   }else{
      for(int i=0;i<listLength(*l);i++){
         for(int j=i+1;j<listLength(*l);j++){
            if(l->contents[i]<l->contents[j]){
               int temp = l->contents[j];
               l->contents[j]=l->contents[i];
               l->contents[i]=temp;
            }
         }
      }
   }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */