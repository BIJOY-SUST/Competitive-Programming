#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,T,len,count=1;
    char S[1000];
    scanf("%d", &T);
    for(i=0; i<T; i++) {
        scanf(" %[^\n]", S);
        len = strlen(S);
        for(j=0; j<len;j++) {
            if(S[j] == ' '){
                count++;
            }
        }
        printf("Number of word = %d\n", count);
        count=1;
    }
    return 0;
}


