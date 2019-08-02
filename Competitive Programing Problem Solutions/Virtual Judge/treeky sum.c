#include<stdio.h>
#include<math.h>
int main(){
    long long int i,j,k,n,t,sum;
    scanf("%lld",&t);
    while(t--){
        sum = 0;
        scanf("%lld",&n);
        sum = n*(n+1)/2;
        for(k=0;pow(2,k)<=n;k++){
            sum = sum -2*pow(2,k);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
