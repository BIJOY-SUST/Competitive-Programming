#include<bits/stdc++.h>
#define mx             5020
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int biton(int p,int pos){return p=p|(1<<pos);}
int bitoff(int p,int pos){return p=p&~(1<<pos);}
bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
int a1[mx],a2[mx],mark[mx],par[mx][mx],pre_par_len[mx][mx];
int n,m;
void print(int x,int y,int ans){
    if(ans==0) return;
    if(a1[x]==a2[y]&&pre_par_len[x][y]==ans){
        print(x-1,par[x][y],ans-1);
        printf("%d ",a1[x]);
    }
    else{
        print(x-1,y,ans);
    }
}
void lcis(){
    int x,y,ans=-1;
    for(int i=0;i<n;i++){
        int cnt=0,link=-1;
        for(int j=0;j<m;j++){
            if(a1[i]==a2[j]&&cnt+1>mark[j]){
                mark[j]=cnt+1;
                par[i][j]=link;
                pre_par_len[i][j]=mark[j];
            }
            else if(a1[i]>a2[j]&&mark[j]>cnt){
                cnt=mark[j];
                link=j;
            }
            if(ans<mark[j]){
                ans=mark[j];
                x=i,y=j;
            }
        }
    }
    printf("%d\n",ans);
    if(ans){
        print(x-1,par[x][y],ans-1);
        printf("%d\n",a1[x]);
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a1[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&a2[i]);

    }

    mem(mark,0);
//    mem(par,-1);
    lcis();
    return 0;
}
/*
Input:
5
2 3 1 4 0
6
10 3 4 1 0 0
6
1 3 4 5 2 3
5
1 2 3 4 5
Output:
2
3 4
*/
