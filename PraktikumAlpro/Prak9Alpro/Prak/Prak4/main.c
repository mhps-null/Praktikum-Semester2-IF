#include <stdio.h>
#include "stack.h" 

int main(){
    Stack s;
    int n; 
    scanf("%d", &n);

    int sum = 0;
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        Push(&s,val);
    }
    for(int i = 0; i < n; i++){
        int max=s.T[i];
        for(int j=i;j<n;j++){
            if(max<s.T[j]){
                max=s.T[j];
            }
        sum+=max;
        }
    }
    printf("%d\n",sum);
    return 0;
}