#include<stdio.h>
int main() {
    int T,N,k,a,b;
    scanf("%d", &T);
    for(k=1; k<=T; k++) {
        scanf("%d", &N);
        a = N%10;
        while(N!=0) {
            b = N%10;
            N = N/10;
        }
        printf("Sum = %d\n", a+b);
    }
    return 0;
}
