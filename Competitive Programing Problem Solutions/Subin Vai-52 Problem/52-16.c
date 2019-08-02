#include<stdio.h>
#include<string.h>
void print_reverse(char str[]){
    int i;
    for(i=strlen(str) - 1; i>=0; i--) {
        printf("%c", str[i]);
    }
}
int main() {
    int i,j,k,T,len;
    char S[1002], S2[1002];

    scanf("%d", &T);
    for(i=0; i<T; i++) {
        scanf(" %[^\n]", S);
        len = strlen(S);
        for(j=0, k=0; j<len;j++) {
            if(S[j] != ' ') {
                S2[k] = S[j];
                k++;
            }
            else if(k>0){
                S2[k] = '\0';
                print_reverse(S2);
                printf(" ");
                k=0;
            }
        }

        if(k>0) {
            S2[k] = '\0';
            print_reverse(S2);
        }

    }
    return 0;
}
