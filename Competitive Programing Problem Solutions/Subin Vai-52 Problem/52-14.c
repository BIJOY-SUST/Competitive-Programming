#include<stdio.h>
#include<string.h>
int main() {
    int T,i,j,count;
    char ch;
    char s[10001];
    scanf("%d", &T);
    for(i=1; i<=2*T; i++) {
    gets(s);
    scanf("%c",&ch);

    count = 0;
        for(j=0; j<strlen(s); j++) {
            if(ch == s[j]) {
                count++;
            }
            else{
             continue;
            }
        }
        printf("%d\n",count);
        printf("\n");
       }
        return 0;
}
