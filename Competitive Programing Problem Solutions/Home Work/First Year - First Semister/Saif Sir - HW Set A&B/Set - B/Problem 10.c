#include<stdio.h>
#include<math.h>
long long int ara[100000000];
long long int ara1[100000000];
int main()
{
    int T;
    long long int i,j,a,m=1,n=90000000,root;
    for(i=2; i<=n; i++){
        ara[i] = 1;
    }
    root = sqrt(n);
    for(i=2; i<=root; i++){
        if(ara[i] == 1) {
            for(j=2; i*j<n; j++) {
                ara[i*j] = 0;
            }
        }
    }
    for(i=2;i<n;i++){
        if(ara[i]==1){
            ara1[m++]=i;
        }
    }
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &a);

        printf("%lld\n", ara1[a]);
    }
    return 0;
}
