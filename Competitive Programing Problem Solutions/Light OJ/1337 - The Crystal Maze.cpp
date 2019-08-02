#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
bool vis[501][501];
char s[501][501];
int sum[501][501];
int ans;
int r,c;
bool vis2[501][501];
int dfs(int x,int y){
    vis[x][y]=true;
    //cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++){
        int tx=fx[i]+x;
        int ty=fy[i]+y;
        if(valid(tx,ty)){
            if(!vis[tx][ty]&&s[tx][ty]!='#'){
                //cout<<tx<<" "<<ty<<endl;
                if(s[tx][ty]=='C'){
                    ans=ans+1;
                    int d=dfs(tx,ty);
                    ans=max(ans,d);
                }
                else{
                    int d=dfs(tx,ty);
                    ans=max(ans,d);
                }
            }
        }
    }
    return ans;
}
void dfs2(int x,int y){
    //cout<<ans<<endl;
    //cout<<valid(x,y)<<endl;
    if(vis2[x][y]==true) return;
    if(valid(x,y)){
    //cout<<"mlan"<<endl;
        vis2[x][y]=true;
        sum[x][y]=ans;
        for(int i=0;i<4;i++){
            int tx=fx[i]+x;
            int ty=fy[i]+y;
            if(s[tx][ty]!='#') dfs2(tx,ty);
        }
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        //mem(s,0);
        int m,n,q;
        scanf("%d%d%d",&m,&n,&q);
        for(int i=0;i<m;i++) //for(int j=0;j<n;j++)
            scanf("%s",s[i]);
        r=m,c=n;
        getchar();
        printf("Case %d:\n",cs);
        mem(vis,false);
        mem(vis2,false);
        mem(sum,0);
        //ans=0;
        while(q--){
            int k,l;
            //cin>>k>>l;
            scanf("%d %d",&k,&l);
            //if(s[x-1][y-1]=='C') ans++;
            int res=0;
            //bug(res);
            //cout<<vis[0][0]<<endl;
            //cout<<k<<" "<<l<<endl;
            if(vis[k-1][l-1]==1){
                //bug(res);
                res=sum[k-1][l-1];
//                cout<<k<<" "<<l<<" "<<res<<endl;
            }
            //if(1) cout<<"man"<<endl;

            else{
                ans=0;
                if(s[k-1][l-1]=='#') continue;
                else if(s[k-1][l-1]=='C') ans=1;
                //bug(res);
                    res=dfs(k-1,l-1);
                //cout<<k<<" "<<l<<" "<<res<<" "<<ans<<endl;

                    dfs2(k-1,l-1);
                    //cout<<sum[1][1]<<endl;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
/*

*/
