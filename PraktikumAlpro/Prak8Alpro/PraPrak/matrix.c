#include "matrix.h"
#include "Boolean.h"
#include <stdio.h>
#include <stdlib.h>

void createMatrix(int nRows, int nCols, Matrix *m){
    m->colEff=nCols;
    m->rowEff=nRows;
};
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
    return(
        i<=ROW_CAP-1 && i>=0 && j>=0 && j<=COL_CAP-1
    );
};
/* Mengirimkan TRUE jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
    return m.rowEff-1;
};
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m){
    return m.colEff-1;
};
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return (
        isMatrixIdxValid(i,j) &&
        i < m.rowEff && j < m.colEff
    );
};
/* Mengirimkan TRUE jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i){
    return m.mem[i][i];
};
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    createMatrix(mIn.rowEff,mIn.colEff,mOut);
    for(int i=0;i<mIn.rowEff;i++){
        for(int j=0;j<mIn.colEff;j++){
            mOut->mem[i][j]=mIn.mem[i][j];
        }
    }
};
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    createMatrix(nRow,nCol,m);
    for(int i=0;i<nRow;i++){
        for(int j=0;j<nCol;j++){
            ElType val;
            scanf("%d",&val);
            m->mem[i][j]=val;
        }
    }
};
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
    for(int i=0;i<m.rowEff;i++){
        for(int j=0;j<m.colEff;j++){
            if(i==m.rowEff-1 && j==m.colEff-1){
                printf("%d",m.mem[i][j]);
            }
            else if(j==m.colEff-1){printf("%d\n",m.mem[i][j]);}
            else{printf("%d ",m.mem[i][j]);}
        }
    }
};
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix m3;
    createMatrix(m1.rowEff,m1.colEff,&m3);
    for(int i=0;i<m1.rowEff;i++){
        for(int j=0;j<m1.colEff;j++){
            m3.mem[i][j]=m1.mem[i][j]+m2.mem[i][j];
        }
    }
    return m3;
};
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix m3;
    createMatrix(m1.rowEff,m1.colEff,&m3);
    for(int i=0;i<m1.rowEff;i++){
        for(int j=0;j<m1.colEff;j++){
            m3.mem[i][j]=m1.mem[i][j]-m2.mem[i][j];
        }
    }
    return m3;
};
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix res;
    createMatrix(m1.colEff,m2.rowEff,&res);
    res.rowEff = m1.colEff;
    res.colEff = m2.rowEff;

    for(int i=0;i<res.rowEff;i++){
        for(int j=0;j<res.colEff;j++){
            res.mem[i][j]=0;
            for(int k=0;k<m1.colEff;k++)
                res.mem[i][j] += m1.mem[i][k] * m2.mem[k][j];
        }
    }
    return res;
};
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyByConst(Matrix m, ElType x){
    for(int i=0;i<m.rowEff;i++){
        for(int j=0;j<m.colEff;j++){
            m.mem[i][j]*=x;
        }
    }
    return m;
};
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k){
    for(int i=0;i<m->rowEff;i++){
        for(int j=0;j<m->colEff;j++){
            m->mem[i][j]*=k;
        }
    }
};
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
    if(isMatrixSizeEqual(m1,m2)){
        for(int i=0;i<m1.rowEff;i++){
            for(int j=0;j<m1.colEff;j++){
                if(m1.mem[i][j]!=m2.mem[i][j]){return FALSE;}
            }
        }
        return TRUE;
    }else{return FALSE;}
};
/* Mengirimkan TRUE jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return (!isMatrixEqual(m1,m2));
};
/* Mengirimkan TRUE jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (m1.colEff==m2.colEff && m1.rowEff==m2.rowEff);
};
/* Mengirimkan TRUE jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
    return (m.colEff*m.rowEff);
};
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
    return (m.colEff==m.rowEff);
};
/* Mengirimkan TRUE jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m){
    if(isSquare(m)){
        for(int i=0;i<m.rowEff;i++){
            for(int j=0;j<m.colEff;j++){
                if(m.mem[i][j]!=m.mem[j][i]){return FALSE;}
            }
        return TRUE;}}
    else{return FALSE;}
};
/* Mengirimkan TRUE jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m){
    if(isSquare(m)){
        for(int i=0;i<m.rowEff;i++){
            for(int j=0;j<m.colEff;j++){
                if (i == j && m.mem[i][j] != 1) return FALSE;
                if (i != j && m.mem[i][j] != 0) return FALSE;
            }
        return TRUE;}
    }else{return FALSE;}
};
/* Mengirimkan TRUE jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m){
    int batas=0.05*(countElmt(m));
    int count=0;

    for(int i=0;i<m.rowEff;i++){
        for(int j=0;j<m.colEff;j++){
            if(m.mem[i][j]!=0){
                count++;
            }
            if(count>batas){return FALSE;}
        }
    }
    return TRUE;
};
/* Mengirimkan TRUE jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m){
    for(int i=0;i<m.rowEff;i++){
        for(int j=0;j<m.colEff;j++){
            m.mem[i][j]*=-1;
        }
    }
    return m;
};
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m){
    for(int i=0;i<m->rowEff;i++){
        for(int j=0;j<m->colEff;j++){
            m->mem[i][j]*=-1;
        }
    }
};
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinant(Matrix m){
    int n = m.rowEff;
    float det = 0;
    if (n == 1) {
        return m.mem[0][0];
    } else if (n == 2) {
        return m.mem[0][0] * m.mem[1][1] - m.mem[0][1] * m.mem[1][0];
    } else {
        for (int f = 0; f < n; f++) {
            Matrix temp;
            temp.rowEff = temp.colEff = n - 1;
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j != f) {
                        temp.mem[subi][subj] = m.mem[i][j];
                        subj++;
                    }
                }
                subi++;
            }
            float cof = ((f % 2 == 0) ? 1 : -1) * m.mem[0][f] * determinant(temp);
            det += cof;
        }
    }
    return det;
};
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m){
    Matrix m3;
    createMatrix(m.colEff,m.rowEff,&m3);
    for(int i=0;i<m.colEff;i++){
        for(int j=0;j<m.rowEff;j++){
            m3.mem[i][j]=m.mem[j][i];
        }
    }
    return m3;
};
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m){
    Matrix m3;
    createMatrix(m->colEff,m->rowEff,&m3);
    for(int i=0;i<m->colEff;i++){
        for(int j=0;j<m->rowEff;j++){
            m3.mem[i][j]=m->mem[j][i];
        }
    }
    *m=m3;
};
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
