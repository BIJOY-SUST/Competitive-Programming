#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    string s;
    cin>>s;
    bool f=false;
    int ans;
//    if(s.length()==1){
//        if(atoi(s[0])%8==0){
//            f=true;
//            ans=atoi(s[0]);
//        }
//    }
//    if(s.length()==2&&!f){
//        if(atoi(s[0]+s[1])%8==0){
//            f=true;
//            ans=atoi(s[0]+s[1]);
//        }
//    }
    if(!f){
        for(int i=0;i<s.length();i++){
            int d=(s[i]-'0');
            if(d%8==0){
                f=true;
                ans=d;
            }
            for(int j=i+1;j<s.length();j++){
                d=(10*(s[i]-'0')+s[j]-'0');
                if(d%8==0){
                    f=true;
                    ans=d;
                }
                for(int k=j+1;k<s.length();k++){
                    d=(100*(s[i]-'0')+(10*(s[j]-'0'))+(s[k]-'0'));
                    if(d%8==0){
                        f=true;
                        ans=d;
                    }
                }
            }
        }
    }
    if(f){
        printf("YES\n%d\n",ans);
    }
    else printf("NO\n");
    return 0;
}
/*

*/
