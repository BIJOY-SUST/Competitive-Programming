//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
//
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define F               first
#define S               second
#define pb              push_back
//#define eb              emplace_back
#define ui              unsigned int
#define ll              long long int
#define ull             unsigned long long int
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vi              vector<int>
#define vll             vector<ll>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define mpii            map<int,int>
#define mpll            map<ll,ll>
#define ump             unordered_map
#define uset            unordered_set
#define PQ              priority_queue
#define nl              '\n'
#define pf              printf
#define sf              scanf
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define grtsrt(v)       sort(v.begin(),v.end(),greater<int>())
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
//#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)

const int mx        = 1e5+10;



double dp[mx];
vi v[mx];
void ami(){
    for(int i=2;i<mx;i++){
        for(int j=i;j<mx;j+=i){
            v[j].pb(i);
        }
    }
}
double lol(int n){
    if(n==1) return 0.0;
    double &ret=dp[n];
    if(ret>=0.0000000) return ret;
    ret=1.0;
    for(int i=0;i<v[n].size();i++){
        ret+=1.0+lol(n/v[n][i]);
    }
    ret=ret/(v[n].size()*1.0);
    return ret;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ami();
    int t;
    sf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        sf("%d",&n);
        mem(dp,-1.0);
        pf("Case %d: %.10f\n",cs,lol(n));
    }
    return 0;
}
/*

*/


