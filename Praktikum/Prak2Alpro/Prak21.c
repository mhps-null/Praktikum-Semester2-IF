#include <stdio.h>
#include <math.h>

int main(){
    long long int a,b;int k=0,prima=0;

    scanf("%lld %lld",&a,&b);

    for(int i=a;i<=b;i++){
        for (int j=2;j<=i;j++){
            if(i%j==0){
                if (i==j){
                    k++;
                }else{break;}
            }
        } 
    }
    printf("%d\n",k);
    

    return 0;
}