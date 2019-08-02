#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

long long i,n,a[999999];
int main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    long long sum = 0;
    for(int i=0;i<n-1;i++){
        sum = sum +a[i]*(i+2);
    }
    sum = sum + a[n-1]*n;
    printf("%lld",sum);
    return 0;
}
