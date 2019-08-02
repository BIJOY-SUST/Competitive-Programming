#include<bits/stdc++.h>
using namespace std;
const int mx = 100011;
typedef long long ll;
map<ll,int> m1;
ll dp[5*mx];
int arr[5*mx];
int n;
int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
    ll ans=0,sum=0;
    scanf("%d",&n);
    dp[0]=0;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        dp[i] = dp[i-1] + arr[i];
        sum += arr[i];
    }
    m1[dp[1]]++;
    for(int i = 3; i < n; ++i) {
        if(dp[i]%3==0 && sum - dp[i] == dp[i]/3) {
            ans += m1[dp[i]/3];
        }
        m1[dp[i]]++;
    }
    if(ans==0) printf("Case #%d: NO\n",i);//cout << ans << endl;
    else printf("Case #%d: YES\n",i);
    }
    return 0;
}
