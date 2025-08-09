#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "boolean.h"
#include "time.h"

int main(){
    int N;long awal=9999,akhir=-1;TIME awl,akhr;

    scanf("%d",&N);
    if (N > 0) {
    for(int i=1;i<=N;i++){
        TIME T1,T2;long dtk;
        printf("[%d]\n",i);
        BacaTIME(&T1);
        BacaTIME(&T2);
        if((TIMEToDetik(T1)>akhir && (TIMEToDetik(T1)>TIMEToDetik(T2)))){
            akhir=TIMEToDetik(T1);
        }
        if((TIMEToDetik(T1)<awal && (TIMEToDetik(T1)<TIMEToDetik(T2)))){
            awal=TIMEToDetik(T1);
        }
        if((TIMEToDetik(T2)>akhir && (TIMEToDetik(T1)<TIMEToDetik(T2)))){
            akhir=TIMEToDetik(T2);
        }
        if((TIMEToDetik(T2)<awal && (TIMEToDetik(T1)>TIMEToDetik(T2)))){
            awal=TIMEToDetik(T2);
        }
        if(TIMEToDetik(T1)>TIMEToDetik(T2)){
            dtk = Durasi(T1, T2);

        }
        else{
            dtk=Durasi(T1,T2);
        }
        printf("%ld\n",dtk);
    }
    awl=DetikToTIME(awal);
    akhr=DetikToTIME(akhir);
    printf("%d:%d:%d\n",awl.HH,awl.MM,awl.SS);
    printf("%d:%d:%d\n",akhr.HH,akhr.MM,akhr.SS);
    }
}