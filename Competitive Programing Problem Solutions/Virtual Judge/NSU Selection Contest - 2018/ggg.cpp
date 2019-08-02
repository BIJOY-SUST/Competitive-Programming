#include<bits/stdc++.h>
#define mx             1050
#define mod            1000007
//#define pi             2*acos(0.0)
//#define ll             long long int
#define pp             pair<int,int>
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
pp dp[mx][mx];
int prothom[mx][30],detio[mx][30];
string s,ss;
pp solve(int l,int r){
    if(l==s.size()||r==ss.size()){
        return {0,1};
    }
    pp &ret = dp[l][r];
    if(ret.first!=-1) return ret;
    ret ={0,1};
    for(int i=0;i<26;i++){
        int ll=prothom[l][i];
        int rr=detio[r][i];
        if(ll==-1||rr==-1) continue;
        pp rrr= solve(ll+1,rr+1);
        if(ret.first<rrr.first+1){
            ret.first=rrr.first+1;
            ret.second=rrr.second;
        }
        else if(ret.first==rrr.first+1){
            ret.second=(ret.second+rrr.second)%mod;
        }
    }
    return ret;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        cin>>s>>ss;
        mem(prothom,-1);
        mem(detio,-1);
        for(int i=0;i<=s.size();i++) {
            for(int j=0;j<=ss.size();j++){
                dp[i][j].first=-1;
            }
        }
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=ss.size();j++){
                dp[i][j].second=0;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=0;j<26;j++){
                prothom[i][j]=prothom[i+1][j];
            }
            prothom[i][s[i]-'a']=i;
        }
        for(int i=ss.size()-1;i>=0;i--){
            for(int j=0;j<26;j++){
                detio[i][j]=detio[i+1][j];
            }
            detio[i][ss[i]-'a']=i;
        }
        int ans = solve(0,0).second;
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
/*
Input:

Output:

*/

