#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

long long n,i,a[300002];
int main()
{
    scanf("%lld",&n);
    for (int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    long long ans=0;
    for (int i=0;i<n-1;i++) ans+=a[i]*(i+2);
    ans+=a[n-1]*n;
    cout <<ans;
    return 0;
}
