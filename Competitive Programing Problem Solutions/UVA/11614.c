#include<stdio.h>
int main(){

    int T,count;
    long long n,i;

    scanf("%d", &T);
    while(T--){
        count = 0;
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            n=n-i;
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
