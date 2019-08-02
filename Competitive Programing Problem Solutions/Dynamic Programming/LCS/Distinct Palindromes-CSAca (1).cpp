#include<bits/stdc++.h>
#define mx             1010
#define mod            1000000007
//#define pi             2*acos(0.0)
#define lli             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
string s;
int dp[mx][mx][26];
int func(int l,int r,int alpha){
    int &ret = dp[l][r][alpha];
    if(ret!=-1) return ret;
    if(l>r) return 0;
    else if(l==r){
        if(s[l]=='a'+alpha) return ret=1;
        else return ret=0;
    }
    else if(s[l]!='a'+alpha||s[r]!='a'+alpha){
        return ret = (1ll*func(l+1,r,alpha)+1ll*func(l,r-1,alpha)-1ll*func(l+1,r-1,alpha))%mod;
    }
    else{
        lli ans=2ll;
        for(int i=0;i<26;i++){
            ans=(ans+1ll*func(l+1,r-1,i))%mod;
        }
        return ret=ans;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    cin>>s;
    mem(dp,-1);
    lli ans=0ll;
    for(int i=0;i<26;i++){
        ans=(ans+func(0,s.length()-1,i))%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
/*
Input:

Output:

*/
