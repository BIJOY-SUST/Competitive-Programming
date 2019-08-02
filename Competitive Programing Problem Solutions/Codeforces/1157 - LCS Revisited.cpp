#include<bits/stdc++.h>
#define mx             1010
#define mod            1000007
#define pi             2*acos(0.0)
#define ll             long long int
#define pp             pair<int,int>
#define bug(x)         printf("X: %d\n",x)
#define ull            unsigned long long int
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int biton(int p,int pos){return p=p|(1<<pos);}
int bitoff(int p,int pos){return p=p&~(1<<pos);}
bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
int ans[mx][mx];
int dp[mx][mx];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0;i<s1.length();i++) ans[i][0]=1;
        for(int i=0;i<s2.length();i++) ans[0][i]=1;
        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans[i][j]=ans[i-1][j-1]+s1[i-1];
                }
                else if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    ans[i][j]=ans[i-1][j];
                }
                else if(dp[i-1][j]<dp[i][j-1]){
                    dp[i][j]=dp[i][j-1];
                    ans[i][j]=ans[i][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                    if(ans[i-1][j]==ans[i][j-1]){
                        ans[i][j]=ans[i-1][j];
                    }
                    ans[i][j]=;
                }
            }
        }
    }
    return 0;
}
/*
Input:

Output:

*/
