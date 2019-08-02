#include<stdio.h>
#include<stdlib.h>
int main(){
    long long int i,j,n,d,r,ara1[100],sum1,sum2,pay;
    while(scanf("%lld %lld %lld",&n,&d,&r)==3){

        if(n==0 && d==0 && r==0){
            break;
        }
        sum1 = 0;
        sum2 = 0;
        pay = 0;
        for(i=0;i<n;i++){
            scanf("%lld",&ara1[i]);
            sum1 = sum1 + ara1[i];
        }
        if(sum1>d){
            sum2 = sum2 +sum1 - d;
        }
        sum1 = 0;
        for(i=0;i<n;i++){
            scanf("%lld",&ara1[i]);
            sum1 = sum1 + ara1[i];
        }
        if(sum1>d){
            sum2 = sum2 +sum1 - d;
        }
        if(sum2>0){
            pay = sum2*r;
            printf("%lld\n",pay);
        }
        else{
            printf("%lld\n",pay);
        }
    }
    return 0;
}
