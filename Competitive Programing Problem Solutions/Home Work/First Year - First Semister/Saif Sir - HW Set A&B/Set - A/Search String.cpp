#include<stdio.h>
int main() {
    int T,i,j,k,N,n1,n2,count = 1;
    char str1[100], str2[100];
    scanf("%[^\n]",str1);
    n1=strlen(str1);
    scanf("%d", &T);
    while(T--){
        scanf(" %[^\n]",str2);
        n2=strlen(str2);
        for(i=0; i<(n1-n2); i++){
            if(str2[0] == str1[i]){
                for(j=1; j<n2; j++){
                    if(str2[j] != str1[i+j]){
                        break;
                    }
                }
                if(j==n2){
                    printf("Case %d: yes\n", count);
                    count++;
                    break;
                }

            }
        }
        if(j!=n2){
        printf("Case %d: no\n", count);
        count++;
        }
    }
    return 0;
}
