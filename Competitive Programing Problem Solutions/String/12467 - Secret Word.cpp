#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mx             1000010
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
string tostr(ll n)     {stringstream rr;rr<<n;return rr.str();}
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool bitcheck(ll p,ll pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
ll dp[mx],B = 347;
ll cal_hash(string s,ll mid){
    ll hash_s=0,x=1;
    for(ll i=mid-1;i>=0;i--){
        hash_s=hash_s+(s[i]*x);
        x=x*B;
    }
    return hash_s;
}
bool rabin_karp(string s,ll mid){
    ll hash_s=cal_hash(s,mid);
    if(hash_s==dp[mid-1]) return true;
    else{
        ll x=1;
        ll power=POW((ll)B,(ll)mid-1);
        for(ll i=mid;i<s.size();i++){
            hash_s=(hash_s-(s[i-mid]*power));
            hash_s=hash_s*B;
            hash_s=hash_s+s[i];
            if(dp[mid-1]==hash_s) return true;
        }
    }
    return false;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
    ll t;
    cin>>t;
    while(t--){
        mem(dp,0);
        string s;
        cin>>s;
        ll x=1,hash_s=0;
        for(int i=0;i<s.size();i++){
            hash_s=hash_s+(s[i]*x);
            x=x*B;
            dp[i]=hash_s;
        }
        ll l=0,h=s.size()+1,mid=0;
        while(l<=h){
            mid=(l+h)/2;
            if(rabin_karp(s,mid)) l=mid+1;
            else h=mid-1;
        }
        for(int i=l-2;i>=0;i--){
            cout<<s[i];
        }
        cout<<'\n';
    }
    return 0;
}
/*
Sample Input
5
colombia
abcdba
neversayeven
neveroddoreven
listentothesilence
Sample Output
c
ba
even
neveroddoreven
sil
*/
