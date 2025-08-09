#include <stdio.h>

int TotalPisang(int a,int b,int c,int d,int e){
    int Total=a+b+c+d+e;
    return Total;
}

double Rata2Pisang(double Total){
    return (Total/5);
}

int main(){
    int a,b,c,d,e,Total;double rata2;

    scanf("%d",&a );
    scanf("%d",&b );
    scanf("%d",&c );
    scanf("%d",&d );
    scanf("%d",&e );
    Total=TotalPisang(a,b,c,d,e);
    printf("%d\n",Total);
    rata2=Rata2Pisang(Total);
    printf("%lf\n",rata2);
    if (rata2>=10){
        printf("Pesta Nimons Sukses!\n");
    }
    else{printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n");}

    return 0;
}