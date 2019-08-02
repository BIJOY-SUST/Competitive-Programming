#include <stdio.h>
int main()
{
    int n, i, flag = 0;
    long long int ara[100000];
    scanf("%d",&n);
    ara[0]=1;
    ara[1]=1;
    for(i=0; i<n; i++){
        if(i==0 || i==1){
            printf("%lld\n", ara[i]);
        }
        else{
            ara[i] = ara[i-2] + ara[i-1];
            printf("%lld\n", ara[i]);
        }
    }
    return 0;
}

