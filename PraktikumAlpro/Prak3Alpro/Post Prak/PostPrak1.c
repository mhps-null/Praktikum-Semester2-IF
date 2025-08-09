#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
    int ganjil=0,genap=0;
    char s[1001];int huruf[26]={0};
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){ 
        s[i]=tolower(s[i]);  
        huruf[s[i]-'a']+=1;
    }

    for(int i=0;i<26;i++){ 
        if (huruf[i]%2==0){
            genap+=1;
        }else{ganjil+=1;}
    }
    
    if (ganjil>1){
        printf("NO\n");
    }else{printf("YES\n");}

    return 0;
}