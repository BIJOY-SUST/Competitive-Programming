#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
long long n,a[50000001];
int main(){

    while(scanf("%lld",&n) && n!=0){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        printf("%lld",a[i]);
        if (i<(n-1))
            printf(" ");
    }
    printf("\n");
    }
    return 0;
}
