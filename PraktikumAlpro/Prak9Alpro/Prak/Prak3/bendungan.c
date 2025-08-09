#include <stdio.h>
#include "stack.h"


int main(){
    int n; scanf("%d", &n);
    int p[n];
    Stack s;
    CreateEmpty(&s);
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
        Push(&s, p[i]);
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        int cur = p[i];
        int idx = i;
        while(cur > p[i+1] && i != n-2){
            i++;
        }
        if(i == n-1 && p[i-1] < cur){
            cur = p[n-1];
            for(int j = idx+1; j <= i-1; j++){
                int a = cur -  p[j];
                if(a > 0){
                    sum+=a;
                }
            }
        }
        else{
            for(int j = idx+1; j <= i; j++){
            sum+= cur -  p[j];
            }
        }
    }

    printf("%d\n", sum);
}