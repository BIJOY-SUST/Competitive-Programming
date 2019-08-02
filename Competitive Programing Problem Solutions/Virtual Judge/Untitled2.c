#include<stdio.h>
#include<math.h>
int main(){
    long long int i,j,k,n,t,sum;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        sum = 0;
        scanf("%lld",&n);
        for(j=1,k=0;j<=n;j++){
            if((long long int)pow(2,k)==j){
                sum = sum -j;
                k++;
            }
            else{
                sum = sum + j;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
