#include<stdio.h>
int main() {
    int T,N,k,i;
    scanf("%d", &T);
    for(k=1; k<=T; k++) {
        scanf("%d", &N);
        int m = 0;
        for(i=5; N/i>=1; i*=i) {
            m=m+N/i;
        }
        printf("%d", m);
        printf("\n");
    }
    return 0;
}
