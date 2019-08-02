#include<stdio.h>
int main(){
    long long int T,N,i,ans;
    scanf("%lld",&T);
    while(T--){

        scanf("%lld",&N);
        ans=1;
        for(i=0;i<N;i++)
            ans=ans*2%100000;
        printf("%lld\n",ans-1);
    }
    return 0;
}
