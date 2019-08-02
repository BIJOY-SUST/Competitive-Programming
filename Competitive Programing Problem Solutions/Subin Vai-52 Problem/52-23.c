#include<stdio.h>
int main(){
    int i,j,l,k,T,n;
    char a[27], aa[27];

    for(i='A', j=0; i<='Z'; i++,j++){
        a[j]=i;
    }
    scanf("%d", &T);
    while(T--){
    scanf(" %[^\n]", aa);
    for(i=0; i<26; i++) {
        for(j=0; j<26; j++) {
            if(aa[i] == a[j]){
                printf("%d", j+1);
            }
        }
    }
    printf("\n");
    }
    return 0;
}
