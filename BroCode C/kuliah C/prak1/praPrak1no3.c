#include <stdio.h>

int main(){
    int N; int i,j,tengah,kiri,kanan;
    scanf("%d",&N);
    tengah=(N/2)+1;

    if (!(N%2==0)){
        for(i=1;i<=N;i++){

            for(j=1;j<=N;j++){

                while((!(i==1))&&(!(j==N))){    
                    if((j==tengah)&&(i==1)){
                        printf("");
                        kiri=tengah-1;
                        kanan=tengah+1;
                    }else{
                        if((j==kiri)||(j==kanan)){
                            printf("");
                        } else{
                            printf(".");
                        }
                    }
                }
            }

        printf("\n");
        }
    } else {printf("tolol");}
    return 0;
}