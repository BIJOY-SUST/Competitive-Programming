#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

///Faster I/O
#define     sfs(a)              scanf("%s",&a)
#define     sfi1(a)             scanf("%d",&a)
#define     sfi2(a,b)           scanf("d",&a,&b)
#define     sfi3(a,b,c)         scanf("d%d",&a,&b,&c)
#define     sfi4(a,b,c,d)       scanf("dd",&a,&b,&c,&d)
#define     sfd1(a)             scanf("%lf",&a)
#define     sfd2(a,b)           scanf("lf",&a,&b)
#define     sfd3(a,b,c)         scanf("lf%lf",&a,&b,&c)
#define     sfd4(a,b,c,d)       scanf("lflf",&a,&b,&c,&d)
#define     sfll1(a)            scanf("%lld",&a)
#define     sfll2(a,b)          scanf("lld",&a,&b)
#define     sfll3(a,b,c)        scanf("lld%lld",&a,&b,&c)
#define     sfll4(a,b,c,d)      scanf("lldlld",&a,&b,&c,&d)
#define     sfull1(a)           scanf("%llu",&a)
#define     sfull2(a,b)         scanf("llu",&a,&b)
#define     sfull3(a,b,c)       scanf("llu%llu",&a,&b,&c)
#define     caseprint(case)     printf("Case %d: ",case ++)

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
#define vll             vector<ull>
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
const int mxn       = 2e6+10;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 4294967296;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here





ull t,n;
string text,pattern,temp_pat;
vll pre;



struct mat{
    ull v[101][101];
};
mat I,org;
vector<ull>longestPrefix(101);

mat matrix_mul(mat a,mat b,ull m){
    mat sol;
    for(ull i=0;i<2;i++){
        for(ull j=0;j<2;j++){
            sol.v[i][j]=0;
            for(ull k=0;k<2;k++){
                sol.v[i][j]+=(a.v[i][k]*b.v[k][j])%m;
                sol.v[i][j]%=m;
            }
        }
    }
    return sol;
}
mat lol(mat org,ull n,ull m){
    mat x=I,y=org;
    while(n){
        if(n&1) x=matrix_mul(x,y,m);
        y=matrix_mul(y,y,m);
        n>>=1;
    }
    return x;
}

void make_org(){
    org=I;

    for(ull i=1;i<=pattern.size()+1;i++){
        for(ull j=0;j<text.size();j++){
            ull k=i;
            while(k>0&&text[j]!=pattern[k]) k=longestPrefix[k-1];
            if(text[j]==pattern[k]) ++k;

            org.v[k][i]++;

        }
    }
}

vll computePrefix(){
    temp_pat=pattern;

    ull m = temp_pat.size();
    ull k=0;
    for(ull i=1;i<m;i++){
        while(k>0&&temp_pat[i]!=temp_pat[k]) k=longestPrefix[k-1];
        if(temp_pat[i]==temp_pat[k]) longestPrefix[i]=++k;
        else longestPrefix[i]=k;
    }
//    for(ull i=0;i<longestPrefix.size();i++){
//        cout<<i<<" "<<longestPrefix[i]<<endl;
//    }
//    cout<<endl;
    return longestPrefix;
}

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);

    for(ull i=0;i<101;i++) I.v[i][i]=1;

    cin>>t;
    while(t--){
        cin>>n;
        cin>>text>>pattern;
        pre = computePrefix();

        make_org();

        mat tt=lol(org,n);

        ull ans=0;
        for(ull i=0;i<pattern.size();i++){
            ans+=tt.v[i][0];
        }
        cout<<ans<<nl;

    }





    return 0;
}
/*

*/
