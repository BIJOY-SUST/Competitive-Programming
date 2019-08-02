#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,ans;
    scanf("%lld",&n);
    ans=n*(n+1)/2-(n-1);
    printf("%lld\n",ans);
    return 0;
}
