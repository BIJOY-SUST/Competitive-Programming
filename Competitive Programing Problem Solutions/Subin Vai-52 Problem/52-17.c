#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,T,len,count=0;
    char S[1000];
    scanf("%d", &T);
    for(i=0; i<T; i++) {
        scanf(" %[^\n]", S);
        len = strlen(S);
        for(j=0; j<len;j++) {
            if(S[j] == 'a'|| S[j] == 'e'|| S[j] == 'i'|| S[j] == 'o'|| S[j] == 'u'){
                count++;
            }
            else{
                continue;
            }
        }
        printf("Number of vowels = %d\n", count);
        count=0;
    }
    return 0;
}

