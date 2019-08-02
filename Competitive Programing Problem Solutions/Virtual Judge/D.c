#include<stdio.h>

int main() {
    int T,i,j,k,N,n1,n2;
    char str1[100], str2[100];

    scanf("%d", &T);
    while(T--){

    scanf(" %[^\n]",str1);
    n1=strlen(str1);
    for(i=0; i<n1; i++){
        if(str2[0] == str1[i]){
            for(j=1; j<n2; j++){
                if(str2[j] != str1[i+j]){
                    break;
                }
            }
            if(j==n2){
                printf("%d\n", i);
                break;
            }
            else{
                printf("Invalid\n");
            }
        }

    }
    }
    return 0;
}
