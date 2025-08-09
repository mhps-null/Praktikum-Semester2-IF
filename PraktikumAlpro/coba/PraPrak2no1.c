#include <stdio.h>
#include <math.h>

double konversiSuhu(double x,char a,char b){
    switch(a){
        case 'C':
        switch(b){
            case 'F':
            x=(x*(9.0/5.0))+32.0;
            break;
            case 'K':
            x=x+273.15;
            break;
        }
        break;
        case 'F':
        switch(b){
            case 'C':
            x=(x-32.0)*(5.0/9.0);
            break;
            case 'K':
            x=((x-32.0)*(5.0/9.0))+273.15;
            break;
        }
        break;
        case 'K':
        switch(b){
            case 'F':
            x=((x-273.15)*9.0/5.0)+32.0;
            break;
            case 'C':
            x=x-273.15;
            break;
        }
        break;
    }
    return floor(x);
}

int main(){
    int N;double x;char a,b;
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%lf %c %c",&x,&a,&b);
        printf("%.2lf\n",konversiSuhu(x,a,b));
    }

    return 0;
}