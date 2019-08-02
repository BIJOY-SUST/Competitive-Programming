#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_set2 = tree<pair <T, string>, null_type, less<pair <T, string>>, rb_tree_tag, tree_order_statistics_node_update>;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct stuc{
    ll l,r,id;
};
vector<stuc >range;
bool cmp(stuc a,stuc b){
    if(a.l==b.l) return a.r<b.r;
    else return a.l<b.l;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        stuc ob;
        ob.l=a,ob.r=b,ob.id=i;
        range.push_back(ob);
    }
    sort(range.begin(),range.end(),cmp);
    priority_queue<ll,vector<ll>,greater<ll> >pq;
    for(ll i=0;i<k-1;i++) pq.push(range[i].r);
    ll left,right,temp=0;
    for(ll i=k-1;i<n;i++){
        ll boro_x=range[i].l;
        pq.push(range[i].r);
        ll choto_y=pq.top();
        pq.pop();
        ll div=choto_y-boro_x+1ll;
        if(div>temp) temp=div,left=boro_x,right=choto_y;
    }
    if(temp==0){
        cout<<temp<<endl;
        for(ll i=1;i<=k;i++) cout<<i<<" ";
    }
    else{
        cout<<temp<<endl;
        for(ll i=0;i<n;i++){
            if(range[i].l<=left&&right<=range[i].r) k--,cout<<range[i].id<<" ";
            if(k==0) break;
        }
    }
    return 0;
}
/*
inputCopy
4 2
1 100
40 70
120 130
125 180
outputCopy
31
1 2
inputCopy
3 2
1 12
15 20
25 30
outputCopy
0
1 2
inputCopy
5 2
1 10
5 15
14 50
30 70
99 100
outputCopy
21
3 4
*/
