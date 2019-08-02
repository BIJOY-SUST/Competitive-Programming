#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k,ans;
    scanf("%lld %lld",&n,&k);
    ans=n/k;
    if((ans==1)||(ans%2==1)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
