#include <stdio.h>
#include <string.h>

int main()
{
    char s[100], r[100];
    int n, i,j;
    while(gets(s)){

    n = strlen(s);

    for ( j = 0, i = n-1; i >= 0; i--){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
            r[j] = s[i];
            j++;
        }
    }
    r[j] = '\0';

    printf("%s\n", r);

    }
    return 0;
}
