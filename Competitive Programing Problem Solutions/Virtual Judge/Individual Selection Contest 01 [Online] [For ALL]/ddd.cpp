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
const int mx        = 1000010;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here

set<char>mm[110];
//bool ff[5];
char mp[110];
//int cc[110];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    fast;
    int t;
    cin>>t;
    while(t--){
        int m,q;
        cin>>q>>m;

        mem(mp,0);
        for(int i=0;i<110;i++) mm[i].clear();

        for(int i=1;i<=m;i++){
            for(int j=1;j<=q;j++){
                char ch,chh;
                cin>>ch>>chh;
                if(chh=='T'){
                    mp[j]=ch;
                }
                else if(chh=='F'){
                    mm[j].insert(ch);
//                    if(mm[j].size()==3){
//                        mem(ff,0);
//                        for(auto x:mm[j]){
//                            ff[x]=1;
//                        }
//                        for(char ccc='A';ccc<='D';ccc++){
//                            if(ff[ccc]==0){
//                                mp[j]=ccc;
//                                break;
//                            }
//                        }
//                    }
                }
            }
        }
        for(int i=1;i<=q;i++){
            if(mp[i]){
                cout<<mp[i];
            }
            else{
                if(mm[i].size()==3){
//                    mem(ff,0);
//                    for(auto x:mm[i]){
//                        ff[x]=1;
//                    }
                    for(char ccc='A';ccc<='D';ccc++){
                        if(mm[i].count(ccc)==0){
                            cout<<ccc;
                            break;
                        }
                    }
                }
                else cout<<"?";
            }
            if(i<q) cout<<" ";
        }
        cout<<nl;
    }
    return 0;
}
/*
3
4
7 2 2 7
8
2 8 1 4 8 2 1 5
5
5 5 5 5 5
*/
