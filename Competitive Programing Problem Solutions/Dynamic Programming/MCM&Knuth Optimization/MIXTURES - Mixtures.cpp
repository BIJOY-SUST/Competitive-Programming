#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
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

int main(){
    int n,p[101],dp[101][101];
    int val[101][101];
    while(scanf("%d",&n)!=EOF){
        //n--;
        mem(p,0);
        mem(dp,0);
        mem(val,0);
        for(int i=0;i<n;i++){
            scanf("%d",&p[i]);
            val[i][i]=p[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                val[i][j]=(val[i][j-1]+p[j])%100;
            }
        }
        //initialization
        ///https://pastebin.ubuntu.com/p/VhfTv8nH7Z/
        for(int i=1;i<=n;i++) dp[i][i]=0;
        int j,k;
        for(int d=1;d<n;d++){
            for(int i=0;i<n-d;i++){
                j=i+d;
                k=i;
                dp[i][j]=dp[i][k]+dp[k+1][j]+val[i][k]*val[k+1][j];
                for(k=i+1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+val[i][k]*val[k+1][j]);
                }
//                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//                cout<<i<<" "<<j<<endl;
            }
        }
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
/*
4
10 5 20 10 25
*/
