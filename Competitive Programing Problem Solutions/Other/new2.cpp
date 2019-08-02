#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define nl              '\n'
#define sf              scanf
#define pf              printf
#define F               first
#define S               second
#define pb              push_back
#define eb              emplace_back
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
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
typedef  tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> o_set;
//bool mark[1000010];vector<int>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(1000010);i+=2){if(mark[i]){for(int j=i*i;j<=1000010;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=1000010;i+=2) if(mark[i]) prime.push_back(i);}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 101;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here

struct data{
    int ele;
    int idx,l,r,k;
};
bool cmp(data a,data b){
    if(a.k==b.k) return a.ele<b.ele;
    else return a.k>b.k;
}
int stree[4*mx];
int lol[mx];
void update(int idx,int l,int r,int pos){
    if(pos<l || pos>r) return;
    if(l==r){
        stree[idx]=1;
        return;
    }
    int left=idx<<1,right=(idx<<1)+1,mid=(l+r)>>1;
    update(left,l,mid,pos);
    update(right,mid+1,r,pos);
    stree[idx]=stree[left]+stree[right];
}
int query(int idx,int l,int r,int i,int j){
    if(i>r||j<l) return 0;
    if(i<=l&&j>=r) return stree[idx];
    int left=idx<<1,right=(idx<<1)+1,mid=(l+r)>>1;
    int p1 = query(left,l,mid,i,j);
    int p2 = query(right,mid+1,r,i,j);
    return p1+p2;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    fast;
    int n;
    cin>>n;
    int x;
    data ob[mx];
    for(int i=1;i<=n;i++){
        cin>>x;
        ob[i].ele=2;
        ob[i].idx=i;
        ob[i].l=0;
        ob[i].r=0;
        ob[i].k=x;
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        ob[i+n].ele=1;
        ob[i+n].idx=i;
        ob[i+n].l=a;
        ob[i+n].r=b;
        ob[i+n].k=c;
    }
    sort(ob+1,ob+n+q+1,cmp);
    for(int i=1;i<=n+q;i++){
//        debug(ob[i].k,ob[i].ele);
        if(ob[i].ele==2){
            update(1,1,n,ob[i].idx);
        }
        else{
//            debug(ob[i].l,ob[i].r);
            int ans=query(1,1,n,ob[i].l,ob[i].r);
//            cout<<ans<<nl;
            lol[ob[i].idx]=ans;
        }

    }
    for(int i=1;i<=q;i++) cout<<lol[i]<<nl;
    return 0;
}
/*
Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2

Output
2
0
3
*/
