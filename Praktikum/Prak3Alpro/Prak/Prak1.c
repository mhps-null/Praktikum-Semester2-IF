#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1001];
    int count[26] = {0};
    int hitung1 = 0; 
    int aman = 1;

    scanf("%s", s);

  
    for (int i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) { 
            count[tolower(s[i]) - 'a']++; 
        }
    }

  
    for (int j = 0; j < 26; j++) {
        if (count[j] % 2 != 0) {
            hitung1++;
        }
    }

    
    if (hitung1 > 1) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }

    return 0;
}
