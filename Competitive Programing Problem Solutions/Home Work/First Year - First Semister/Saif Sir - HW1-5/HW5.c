#include <stdio.h>
int main()
{
    int n, i, flag = 0;
    long long int ara[10000];
    printf("Enter a integer: ");
    scanf("%d",&n);
    ara[0]=0;
    ara[1]=1;
    for(i=0; i<=n; i++){
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