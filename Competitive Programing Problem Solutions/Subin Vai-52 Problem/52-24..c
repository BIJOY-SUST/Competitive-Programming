#include<stdio.h>
int main() {
    int T,k,i,m;
    char a[101];
    scanf("%d", &T);
    for(k=1; k<=T; k++) {
        scanf("%d", &m);
        for(i=0; i<m; i++) {
            scanf("%d", &a[i]);
        }
        for(i=0; i<m; i=i+2){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
