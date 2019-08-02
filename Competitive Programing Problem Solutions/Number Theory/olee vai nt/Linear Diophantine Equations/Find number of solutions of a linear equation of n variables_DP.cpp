#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int count_sol(int n,int rhs){
    int dp[rhs+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=v[i];j<=rhs;j++){
            dp[j]+=dp[j-v[i]];
//            cout<<j<<" "<<dp[j]<<'\n';
        }
    }
    return dp[rhs];
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int a,k=7,rhs;
        while(k--){
            cin>>a;
            v.push_back(a);
        }
        cin>>rhs;
        int n=v.size();
        cout<<count_sol(n,rhs)<<'\n';
    }
    return 0;
}
