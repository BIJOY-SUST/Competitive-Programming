#include<stdio.h>
int main() {
    int T,N,k;

    scanf("%d", &T);
    for(k=1; k<=T; k++) {
        long long int i,ans = 1;
        scanf("%d", &N);
        if(N>0){
            for(i=2; i<=N; i++) {
                ans = ans*i;
            }
            printf("%lld", ans);
            printf("\n");
        }

        else if(N == 0) {
            printf("1");
            printf("\n");
        }

    }
    return 0;
}

