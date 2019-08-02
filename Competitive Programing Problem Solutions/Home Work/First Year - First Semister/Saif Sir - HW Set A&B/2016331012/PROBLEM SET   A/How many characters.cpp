#include<stdio.h>
#include<string.h>

int main()
{
    int i,T,len;
    char S[1000];
    scanf("%d", &T);
    for(i=1; i<=T; i++) {
        scanf(" %[^\n]", S);
        len = strlen(S);
        printf("Case %d: %d\n",i, len);
    }
    return 0;
}



