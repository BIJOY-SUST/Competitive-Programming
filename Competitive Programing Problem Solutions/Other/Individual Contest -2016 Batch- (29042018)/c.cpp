//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

//#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>

//#include <ext/pb_ds/detail/standard_policies.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ll              long long int
#define ull             unsigned long long int
#define ld              long double

#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vi              vector<int>
#define vll             vector<ll>
#define vc              vector<char>
#define vs              vector<string>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define sti             stack<int>
#define stll            stack<ll>
#define qi              queue<int>
#define qll             queue<ll>
#define sei             set<int>
#define sell            set<ll>
#define sec             set<char>
#define ses             set<string>
#define pqll            priority_queue<ll>
#define pqgrt           priority_queue<ll,vector<ll>,greater<ll> >
#define mpii            map<int,int>
#define mpll            map<ll,ll>
#define mpsll           map<string,ll>
#define mplls           map<ll,string>
#define mpcll           map<char,ll>
#define umpii           unordered_map<int,int>
#define umpll           unordered_map<ll,ll>
#define umpsll          unordered_map<string,ll>
#define umplls          unordered_map<ll,string>
#define umpcll          unordered_map<char,ll>

#define F               first
#define S               second
#define pb              push_back
#define pp              pop_back
#define UB              upper_bound
#define LB              lower_bound

#define pf                  printf
#define sfc(a)              scanf("%c",&a)
#define sfs(a)              scanf("%s",&a)
#define sfi1(a)             scanf("%d",&a)
#define sfi2(a,b)           scanf("%d %d",&a,&b)
#define sfi3(a,b,c)         scanf("%d %d %d",&a,&b,&c)
#define sfi4(a,b,c,d)       scanf("%d %d %d %d",&a,&b,&c,&d)
#define sfd1(a)             scanf("%lf",&a)
#define sfd2(a,b)           scanf("%lf %lf",&a,&b)
#define sfd3(a,b,c)         scanf("%lf %lf %lf",&a,&b,&c)
#define sfd4(a,b,c,d)       scanf("%lf %lf %lf %lf",&a,&b,&c,&d)
#define sfll1(a)            scanf("%lld",&a)
#define sfll2(a,b)          scanf("%lld %lld",&a,&b)
#define sfll3(a,b,c)        scanf("%lld %lld %lld",&a,&b,&c)
#define sfll4(a,b,c,d)      scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define sfull1(a)           scanf("%llu",&a)
#define sfull2(a,b)         scanf("%llu %llu",&a,&b)
#define sfull3(a,b,c)       scanf("%llu %llu %llu",&a,&b,&c)
#define sfull4(a,b,c,d)     scanf("%llu %llu %llu %llu",&a,&b,&c,&d)

#define ang(a, b, c)        acos((b*b+c*c-a*a)/(2.0*b*c))
#define dist(x1,y1,x2,y2)   sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define rev(v)              reverse(v.begin(),v.end())
#define srt(v)              sort(v.begin(),v.end())
#define grtsrt(v)           sort(v.begin(),v.end(),greater<int>())
#define all(v)              v.begin(),v.end()
#define minv(v)             *min_element(v.begin(),v.end())
#define maxv(v)             *max_element(v.begin(),v.end())
#define cntv(v,a)           count(v.begin(),v.end(),a)
#define one(x)              __builtin_popcount(x)
#define valid(tx,ty)        tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)        memset(arr,val,sizeof(arr))
#define Unique(x)           x.erase(unique(x.begin(),x.end()),x.end())
#define fast                ios_base::sync_with_stdio(false),cin.tie(NULL)
#define forstl(it,v)        for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define loop(i,n)           for(int i=0;i<n;i++)
#define loop1(i,n)          for(int i=1;i<=n;i++)
#define case_print          printf("Case %d: ",cs)

//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//
//template <class T1> void deb(T1 e1){cout<<e1<<endl;}
//template <class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
//template <class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
//template <class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
//template <class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
//template <class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


#define mx              100010
#define inf             0x3f3f3f3f
#define mod             1000000007
#define PI              2*acos(0.0)
#define E               2.71828182845904523536

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template <typename T> using ordered_set2 = tree<pair <T, string>, null_type, less<pair <T, string>>, rb_tree_tag, tree_order_statistics_node_update>;
//ll histogram(ll arr[],ll n){ll top,i=0,sum=0,max_area=0;stack<ll>st;st.push(0);while(i<n){if(st.empty()||arr[st.top()]<=arr[i]) st.push(i++);else{top=st.top();st.pop();if(st.empty())sum=arr[top]*i;else sum=arr[top]*(i-st.top()-1);max_area=max(sum,max_area);}}while(!st.empty()){top=st.top();st.pop();if(st.empty()) sum=arr[top]*i;else sum=arr[top]*(i-st.top()-1);max_area=max(sum,max_area);}return max_area;}
//ll ext_gcd(ll a,ll b,ll *x,ll *y){if(a==0){*x=0;*y=1;return b;}ll x1,y1;ll gcd = ext_gcd(b%a,a,&x1,&y1);*x=y1-(b/a)*x1;*y=x1;return gcd;}
//bool mark[mx];vector<ll>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(ll i=3;i<=(ll)sqrt(mx);i+=2){if(mark[i]){for(ll j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(ll i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}
///code start here

vi edge[mx];
int vis[mx],level[mx],sum[mx];
void dfs(int u){
    vis[u]=1;
    level[u]=1;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(!vis[v]){
            dfs(v);
            level[u]+=level[v];
            sum[u]=max(sum[u],level[v]);
        }
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    sfi1(t);
    loop1(cs,t){
        int n;
        sfi1(n);
        loop1(i,n-1){
            int u,v;
            sfi2(u,v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        int tot=1e6,no;
        mem(vis,0);
        mem(level,0);
        mem(sum,0);
        dfs(1);
        loop1(i,n){
            int d=max(sum[i],n-level[i]);
            if(tot>d){
                tot=d;
                no=i;
            }
        }
        pf("%d %d\n",no,tot);
        loop(i,mx) edge[i].clear();

    }
    return 0;
}
/*

*/
