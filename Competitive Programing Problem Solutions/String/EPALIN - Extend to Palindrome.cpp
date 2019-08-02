/*
using - RK
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mx             100010
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
string Rabin_Karp(string text){
    ll p2=text.size();
    string ss = text;
    reverse(ss.begin(),ss.end());
    if(text==ss){
        return text;
    }
    else{
        ll B = 999983,hash_text=0,hash_pattern=0,x=1,cnt=0;
        for(ll i=0;i<ss.size();i++){
            hash_text=(hash_text+(ss[i]*x)%mod)%mod;
            x=(x*B)%mod;
            hash_pattern=(hash_pattern*B)%mod;
            hash_pattern=(hash_pattern+ss[i])%mod;
            if(hash_text==hash_pattern) cnt=i;
        }

        string ans = text+ss.substr(cnt+1,ss.size());
        return ans;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
//    ll t;
//    cin>>t;
//    for(ll cs=1;cs<=t;cs++){
        string text;
        while(cin>>text){
            string ans=Rabin_Karp(text);
            cout<<ans<<'\n';
        }
//    }
    return 0;
}
/*
Input:
aaaa
abba
amanaplanacanal
xyz

Output:
aaaa
abba
amanaplanacanalpanama
xyzyx
*/