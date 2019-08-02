//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
#define toint(s)       atoi(s.c_str())
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
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        ll d;
        cin>>d;
        string s;
        cin>>s;
        ll cnt=1,dam=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='C'){
                cnt=2*cnt;
            }
            else{
                dam+=cnt;
            }
        }
        if(dam<=d){
            printf("Case #%d: 0\n",cs);
        }
        else if(cnt==1){
            printf("Case #%d: IMPOSSIBLE\n",cs);
        }
        else{
            ll operation=0;
            bool flag=false;
            while(1){
                operation++;
                bool f=false;
                bool f2=false;
                for(int i=s.length()-1;i>=0;i--){
                    if(s[i]=='S') f=true;
                    else if(f==true&&s[i]=='C'){
                        f2=true;
                        break;
                    }
                }
                if(f2==false) break;
                else{
                    for(int i=s.length()-1;i>=1;i--){
                        if(s[i]=='S'&&s[i-1]=='C'){
                            swap(s[i-1],s[i]);
                            ++ans;
                            break;
                        }
                    }
                    cnt=1,dam=0;
                    for(int i=0;i<s.length();i++){
                        if(s[i]=='C'){
                            cnt=2*cnt;
                        }
                        else{
                            dam+=cnt;
                        }
                    }
                    if(dam<=d){
                        flag=true;
                        break;
                    }
                }
                if(operation>=200){
                    break;
                }
            }
            if(flag) printf("Case #%d: %lld\n",cs,ans);
            else printf("Case #%d: IMPOSSIBLE\n",cs);
        }
    }
    return 0;
}
/*
Case #1: 1
*/
