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
vector<ll> computePrefix(string pattern){
    ll m = pattern.size();
    vector<ll>longestPrefix(m);
    ll k=0;
    for(ll i=1;i<m;i++){
        while(k>0&&pattern[i]!=pattern[k]) k=longestPrefix[k-1];
        if(pattern[i]==pattern[k]) longestPrefix[i]=++k;
        else longestPrefix[i]=k;
    }
//    for(int i=0;i<longestPrefix.size();i++){
//        cout<<i<<" "<<longestPrefix[i]<<endl;
//    }
//    cout<<endl;
    return longestPrefix;
}
ll KMP(string text,string pattern){
    ll n=text.size();
    ll m=pattern.size();
    vector<ll>longestPrefix = computePrefix(pattern);
    ll k=0,ans=0;
    for(ll i=0;i<n;i++){
        while(k>0&&text[i]!=pattern[k]) k=longestPrefix[k-1];
        if(text[i]==pattern[k]) k++;
        if(k==m){
            ans++;
            k=longestPrefix[k-1];
//            cout<<i-m+1<<endl;
        }
    }
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
    ll t;
    cin>>t;
    for(ll cs=1;cs<=t;cs++){
        string pattern,text;
        cin>>text>>pattern;
        ll ans=KMP(text,pattern);
        cout<<"Case "<<cs<<": "<<ans<<'\n';
    }
    return 0;
}
/*
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
*/

