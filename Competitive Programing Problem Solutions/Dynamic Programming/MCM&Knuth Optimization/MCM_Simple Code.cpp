#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
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
    int i,j,k,d,n,p[1001],dp[101][101];
    cin>>n;
    for(i=0;i<=n;i++){
        cin>>p[i];
    }
    //initialization
    for(i=1;i<=n;i++) dp[i][i]=0;
    for(d=1;d<n;d++){
        for(i=1;i<=n-d;i++){
            j=i+d;
            //k=i;
            //dp[i][j]=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
            dp[i][j]=1e9;
            for(k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
            }
//            cout<<i<<" "<<j<<endl;
        }
    }
    cout<<"Minimum Operation: "<<dp[1][n];
    return 0;
}
/*
Input
4
10 5 20 10 25
Output
3500
*/
