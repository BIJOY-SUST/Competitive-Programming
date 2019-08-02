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
vector<ll>computePrefix(string s){
    ll m=s.length();
    vector<ll>longestPrefix(m);
    ll k=0;
    for(ll i=1;i<m;i++){
        while(k>0&&s[k]!=s[i]) k=longestPrefix[k-1];
        if(s[k]==s[i]) longestPrefix[i]=++k;
        else longestPrefix[i]=k;
    }
    return longestPrefix;
}
string KMP(string text){
    string s=text;
    reverse(s.begin(),s.end());
    if(s==text){
        return text;
    }
    else{
        ///Trick 1
        /*
        ll n=s.length();
        string ss=s+text;
        vector<ll>longestPrefix = computePrefix(ss);
        ll k =longestPrefix[ss.length()-1];
        string ans=text+s.substr(k,s.size()-1);
        return ans;
        */
        ///Trick 2
        vector<ll>longestPrefix = computePrefix(s);
        ll k=0,cnt;
        for(ll i=0;i<text.length();i++){
            while(k>0&&text[i]!=s[k]) k=longestPrefix[k-1];
            if(text[i]==s[k]) ++k,cnt=k;
        }
        string ans=text+s.substr(k,text.size()-1);
        return ans;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
    string text;
    while(cin>>text){
        string ans=KMP(text);
        cout<<ans<<'\n';
    }
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
