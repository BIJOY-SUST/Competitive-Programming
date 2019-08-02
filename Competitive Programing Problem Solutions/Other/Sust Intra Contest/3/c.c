#include<stdio.h>
#include<math.h>
int main(){
    long long int t,n,i,ans;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        scanf("%lld",&n);
        ans = n*(n+3)/2;
        printf("%lld\n",ans);
    }
    return 0;
}
