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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    string text,alpha;
    cin>>text>>alpha;
    ull k;
    cin>>k;
    set<pair<ull,ull> >ans;
    for(int i=0;i<text.size();i++){
        ull x=1,x2=1,bad=0,B1=347,B2=999983,h1=0,h2=0;
        for(int j=i;j<text.size();j++){
            if(alpha[text[j]-'a']=='0') bad++;
//            cout<<bad<<endl;
            if(bad>k) break;
            h1=h1+(text[j]*x);
            h2=h2+(text[j]*x2);
            x=(x*B2);
            x2=x2*B1;
            ans.insert({h1,h2});
//            cout<<i<<" "<<j<<endl;
        }
    }
//    for(auto it:ans) cout<<it<<" ";
//    cout<<endl;
    cout<<ans.size()<<'\n';
    return 0;
}
/*

*/
