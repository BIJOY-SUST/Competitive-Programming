#include<bits/stdc++.h>

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
#define unique(x)      x.erase(unique(x.begin(),x.end()),x.end())
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
#define forstl(x)      for(__typeof(x.begin()) it=(x.begin());it!=(x.end());++it)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll boss(string s){
    ll cnt=0;
    for(ll i=0;i<s.length();i++) if((s[i]-'0')%3==0) ++cnt;
    return cnt;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll t;
    cin>>t;
    for(ll cs=1;cs<=t;cs++){
        string s;
        cin>>s;
        ll sum=0;
        for(ll i=0;i<s.length();i++){
            sum+=(s[i]-'0');
        }
        bool flag=false;
        for(ll i=0;i<s.length();i++){
            if((sum-(s[i]-'0'))%3==0) flag=true;
        }
        printf("Case %d: ",cs);
        if(sum%3==0){
            if(boss(s)%2==0) cout<<"T\n";
            else cout<<"S\n";
        }
        else if(flag){
            if(boss(s)%2==0) cout<<"S\n";
            else cout<<"T\n";        }
        else cout<<"T\n";

    }
    return 0;
}
