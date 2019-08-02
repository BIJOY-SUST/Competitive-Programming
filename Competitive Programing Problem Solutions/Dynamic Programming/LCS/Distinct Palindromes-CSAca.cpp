#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mx             1010
#define inf            0x3f3f3f3f
#define mod            1000000007
#define PI             2*acos(0.0)
#define E              2.71828182845904523536
#define ll             long long int
#define ull            unsigned long long int
#define pii            pair<int,int>
#define pll            pair<ll,ll>
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
string s;
int dp[mx][mx][26];
int func(int l,int r,int alpha){
    int &ret = dp[l][r][alpha];
    if(ret!=-1) return ret;
    if(l>r) return 0;
    else if(l==r){
        if(s[l]=='a'+alpha) return ret=1;
        else return ret=0;
    }
    else if(s[l]!='a'+alpha||s[r]!='a'+alpha){
        return ret = (1ll*func(l+1,r,alpha)+1ll*func(l,r-1,alpha)-1ll*func(l+1,r-1,alpha))%mod;
    }
    else{
        ll ans=2ll;
        for(int i=0;i<26;i++){
            ans=(ans+1ll*func(l+1,r-1,i))%mod;
        }
        return ret=ans;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    cin>>s;
    mem(dp,-1);
    ll ans=0ll;
    for(int i=0;i<26;i++){
        ans=(ans+func(0,s.length()-1,i))%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
/*
Input:
aaaaa
abbaab
Output:
5
10
*/
