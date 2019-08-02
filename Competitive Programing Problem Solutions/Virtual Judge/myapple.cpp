#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

long long i,n,a[999999];
int main(){
    int i,j;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    long long sum = 0;
    for(i=0;i<n;i++){

        for(j=i;j<n;j++){
            sum = sum + a[j];
        }
        sum = sum + a[i];
    }
    sum = sum -a[i-1];
    printf("%lld",sum);
    return 0;
}
