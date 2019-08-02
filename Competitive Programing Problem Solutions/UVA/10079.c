#include<stdio.h>

int main()
{
    int long long N, i, m=1;
    scanf("%lld", &N);
    if(N < 0){
        return 0;
    }
    if(N > 0) {
        for(i=1; i<=N; i++) {
        m = m+i;
    }
    printf("%lld\n", m);
    }
    return 0;
}
