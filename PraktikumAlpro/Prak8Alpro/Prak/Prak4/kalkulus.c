#include "Boolean.h"
#include "matrix.h"

Matrix dilate(Matrix v, int scale){
    for(int i=0;i<v.rowEff;i++){
        for(int j=0;j<2;j++){
            if(j==0){
                v.mem[i][j]*=scale;
            }else if(j==1){
                v.mem[i][j]*=scale;
            }
        }
    }
    return v;
};
/* Setiap titik (x, y) menjadi (x*scale, y*scale) */

Matrix translate(Matrix v, int dx, int dy){
    for(int i=0;i<v.rowEff;i++){
        for(int j=0;j<2;j++){
            if(j==0){
                v.mem[i][j]+=dx;
            }else if(j==1){
                v.mem[i][j]+=dy;
            }
        }
    }
    return v;
};
/* Setiap titik (x, y) menjadi (x+dx, y+dy) */

Matrix reflect(Matrix v, char axis){
    Matrix m;
    createMatrix(v.rowEff,v.colEff,&m);
    copyMatrix(v,&m);

    for(int i=0;i<v.rowEff;i++){
        for(int j=0;j<2;j++){
            if(j==0){
                m.mem[i][j]=(-1)*v.mem[i][1];
            }else if(j==1){
                m.mem[i][j]=(-1)*v.mem[i][0];
            }
        }
    }
    return m;
};
/* 'x' → y = -y, 'y' → x = -x */

Matrix rotate(Matrix v, int degree){
    int cos,sin;
        if(degree==0){
            cos=1;sin=0;
        }else if(degree==90){
            cos=0;sin=1;
        }else if(degree==180){
            cos=-1;sin=0;
        }else{
            cos=0;sin=-1;
        }

    for(int i=0;i<v.rowEff;i++){
        v.mem[i][0]=(v.mem[i][0]*cos) + (v.mem[i][1]*sin);
        v.mem[i][1]=(v.mem[i][0]*(-1)*sin)+(v.mem[i][1]*cos);
    }

    return v;
};
/* Memutar setiap titik (x, y) sebesar degree derajat searah jarum jam dari (0,0) */
/* Gunakan rumus rotasi:
   x' = x * cosθ + y * sinθ
   y' = -x * sinθ + y * cosθ
   degree hanya 0, 90, 180, 270 (bisa pakai konstanta tanpa trigonometri float) */
/* cos0 = 1, sin0 = 0*/
/* cos90 = 0, sin90 = 1*/
/* cos180 = -1, sin180 = 0*/
/* cos270 = 0, sin270 = -1*/
/* DEGREE SUDAH PASTI 4 JENIS, HARDCODE SAJA, TIDAK PERLU PAKE <math.h> */
