#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
ll Rabin_Karp(string pattern,string text){
    ll p1=pattern.size();
    ll p2=text.size();
    if(p1>p2||p1==0||p2==0){
        return 0;
    }
    else{
        ll B = 999983,hash_taxt=0,hash_pattern=0,x=1;
        ll power = BigMod((ll)B,(ll)p1-1,(ll)mod);
        for(ll i=p1-1;i>=0;i--){
            hash_pattern=(hash_pattern+(pattern[i]*x)%mod)%mod;
            hash_taxt=(hash_taxt+(text[i]*x)%mod)%mod;
            x=(x*B)%mod;
        }
        vector<ll>ans;
        ans.clear();
        if(hash_pattern==hash_taxt) ans.push_back(0);
        for(int i=p1;i<p2;i++){
            hash_taxt=(((hash_taxt-(text[i-p1]*power)%mod)%mod)+mod)%mod;
            hash_taxt=(hash_taxt*B)%mod;
            hash_taxt=(hash_taxt+text[i])%mod;
            if(hash_pattern==hash_taxt){
                ans.push_back(i-p1+1);
            }
        }
        return ans.size();
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
    ll t;
    cin>>t;
    for(ll cs=1;cs<=t;cs++){
        string pattern,text;
        cin>>text>>pattern;
        ll ans=Rabin_Karp(pattern,text);
        cout<<"Case "<<cs<<": "<<ans<<'\n';
    }
    return 0;
}
/**
Sample input:
4
axbyczd
abc
abcabcabcabc
abc
aabacbaabbaaz
aab
aaaaaa
aa
Sample output:
Case 1: 0
Case 2: 4
Case 3: 2
Case 4: 5
**/
