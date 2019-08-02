#include<bits/stdc++.h>
#define mx             1010
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
int arr[mx];
int dp[mx][mx];
int func( int S[], int m, int n ){
    int i, j, x, y;
    int dp[n+1][m];
    for (i=0; i<m; i++) dp[0][i] = 1;
    for (i = 1; i < n+1; i++){
        for (j = 0; j < m; j++){
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? dp[i - S[j]][j]: 0;
            // Count of solutions excluding S[j]
            y = (j >= 1)? dp[i][j-1]: 0;
            // total count
            dp[i][j] = x + y;
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    return dp[n][m-1];
}
int main(){
    mem(dp,0);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d",&arr[i]);
    int n;
    scanf("%d",&n);
    printf("Total Solution: %d\n", func(arr, m, n));
    return 0;
}

