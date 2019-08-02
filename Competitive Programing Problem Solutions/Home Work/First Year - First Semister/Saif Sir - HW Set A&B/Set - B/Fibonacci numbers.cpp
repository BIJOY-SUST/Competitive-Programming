#include <stdio.h>
int main()
{
    int n, i;
    long long int ara[10000];
    while(scanf("%d",&n)){
    ara[0]=0;
    ara[1]=1;
    for(i=0; i<=n; i++){
        if(i==0){
            ara[0] = 0;
        }
        else if(i==1){
            ara[1] = 1;
        }
        else{
            ara[i] = ara[i-2] + ara[i-1];

        }
    }
    printf("%lld\n", ara[i-1]);
    }
    return 0;
}
