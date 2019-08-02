#include <stdio.h>

int main(){
    int T;
    long long int L, W, H, sum, count = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%lld %lld %lld", &L, &W, &H);
        sum = (L*H + L*W + W*H);
        printf("Case %lld: %lld\n", count, sum);
        count++;
    }
    return 0;
}


