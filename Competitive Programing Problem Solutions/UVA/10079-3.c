#include<stdio.h>

int main(){
    long long int n, m;
    while(scanf("%lld", &n)){
        if(n < 0) {
            return 0;
        }
        else if(n>=0) {
            m = 1 + n * (n + 1) / 2;
            printf("%lld\n", m);
        }
    }
    return 0;
}
