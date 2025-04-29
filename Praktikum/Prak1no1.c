#include <stdio.h>
#include <math.h>

int main(){

    int N,count = 1,panjang=0,pembagi1,pembagi2,hasil1,hasil2,yes=0;
    scanf("%d",&N);

    while (count<=N)
    {
        count*=10;
        panjang++;
    }

    if ((panjang%2)==0)
    {
        for (int i=1;i<=(panjang/2);i++)
        {
            pembagi1=pow(10,panjang-i);
            pembagi2=pow(10,i);
            hasil1=N/(pembagi1);
            hasil2=N%(pembagi2);
            if (hasil1!=hasil2){
                for(j )
                hasil1/=10;
                hasil2=hasil2%10;
            }
            printf("%d %d\n",hasil1,hasil2);
            
        }
    }
    // if (yes=1){
    //     printf("1\n");
    // } else {printf("0\n");}

    return 0;
}