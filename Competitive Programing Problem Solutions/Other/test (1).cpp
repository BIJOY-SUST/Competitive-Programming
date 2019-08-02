
/**
SUST_GreyScale
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define nl "\n"
#define debug(x) cout<< #x" " << x<<endl
#define fwrite(p) freopen(p,"w",stdout)
#define fread(p) freopen(p,"r",stdin)
#define PI 2*acos(0.0)
#define mem(s,k) memset(s, k, sizeof(s))
//
//template<typename T> POW(T b, T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//template<typename T> BigMod(T b, T p, T m) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%m;b=(b*b)%m;p>>=1;}return Ans%m;}
//template<typename T> ModInverse(T p, T m) {return BigMod(p,m-2,m);}
////template<typename T> using orderedSet = tree< T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//
//////-------------------- Bit Manipulation ---------//
////int bitOn(int N, int pos) {return N=N OR (1<<pos);}
////int bitOff(int N, int pos) {return N= N&~(1<<pos);}
////int bitCheck(int N, int pos) {return (bool)(N & (1<<pos));}
//////-----------------------------------------------////
//
//////-----------Graph Moves----------//
//const int xx[] = {0,0,1,-1};
//const int yy[] = {1,-1,0,0};
//const int xx_king[] = {0,0,1,-1,1,1,-1,-1};
//const int yy_king[] = {1,-1,0,0,1,-1,1,-1};
//const int xx_knight[] = {-2,-1,1,2,2,1,-1,-2};
//const int yy_knight[] = {1,2,2,1,-1,-2,-2,-1};
//////------------------------------//
vector<int> v;
int n,m,k,ans=0;
int g[20][20];
bool check()
{
//    for(int i=0; i<v.size(); i++) cout<<v[i]<<' ';
//    cout<<endl;
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v.size(); j++)
        {
            if(g[v[i]][v[j]]==0)
                return false;
        }
    }
    return true;
}
void call()
{
    for(int i=0;i<(1<<n);i++){
        v.clear();
        for(int j=0;j<20;j++){
            if(i & (1<<j)) v.push_back(j);
        }
        if(check()) {
            int sz = v.size();
            ans = max(ans,sz);
        }
    }
}

//void call(int pos)
//{
//    if(pos>=n)
//        return;
//    v.push_back(pos);
//    if(check())
//    {
//        int sz=v.size();
//        ans=max(ans,sz);
//    }
//    call(pos+1);
//    v.pop_back();
//
//    call(pos+1);
//}

int main()
{
    int t;
    cin >> t;
    int cs=1;
    while(t--)
    {
        memset(g,0,sizeof g);
        v.clear();
        ans=0;
        cin >> n >> m >> k;
        for(int i=0; i<m; i++)
        {
            int a,b;
            cin >> a >> b;
            g[a][b]=1;
            g[a][a]=1;
            g[b][b]=1;
            g[b][a]=1;
        }

        call();
        printf("Case %d: ",cs++);
        if(ans<=k)
            cout<< "Yes"<<endl;
        else
            cout<< "No"<<endl;
    }
}
/*
5 7 5
1 0
1 3
1 4
0 3
0 4
3 4
1 2
*/
