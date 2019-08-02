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
int l_prefix[1000010];
void comp_prefix(string s){
    int len=s.length();
    int k=0;
//    cout<<len<<endl;
    for(int i=1;i<len;i++){
//        cout<<i<<endl;
        while(k>0&&s[i]!=s[k]) k=l_prefix[k-1];
        if(s[i]==s[k]) l_prefix[i]=++k;
        else l_prefix[i]=k;
//        cout<<i<<" "<<k<<" "<<l_prefix[i]<<endl;
    }
//    cout<<"BIJOY"<<endl;
//    for(int i=0;i<len;i++) cout<<s[i]<<" "<<i<<" "<<l_prefix[i]<<endl;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
    string s;
    cin>>s;
//    cout<<"BIJOY"<<endl;
    comp_prefix(s);
    int len=s.length();
//    cout<<len<<endl;
    int cnt=0;
    cnt = l_prefix[len-1];
    bool f=false;
    for(int i=0;i<len-1;i++){
        if(l_prefix[i]==cnt){
            f=true;
            break;
        }
    }
//    cout<<len<<" "<<cnt<<" "<<f<<endl;
    if(!f) cnt=l_prefix[cnt-1];
//    cout<<cnt<<endl;
    if(cnt!=0){
        string ans=s.substr(0,cnt);
        cout<<ans<<'\n';
    }
    else{
        cout<<"Just a legend\n";
    }
    return 0;
}
/*
qwertyqwertyqwerty

*/
