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
#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<m
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
char a[101][101];
int n,m;
int dis[101][101];
void bfs(int st,int en){
    for(int i=0;i<101;i++) for(int j=0;j<101;j++){
        dis[i][j]=1e7;
    }
    dis[st][en]=0;
    queue<pii >q;
    q.push({st,en});
//    cout<<n<<" "<<m<<endl;
    while(!q.empty()){
        pii u=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=u.first+fx[i];
            int ty=u.second+fy[i];
//            cout<<tx<< " "<<ty<<endl;
            if(valid(tx,ty)){
//                    cout<<"BIJOY"<<endl;
                if(a[tx][ty]=='#'){
                    if(dis[tx][ty]>dis[u.first][u.second]+1){
                        q.push({tx,ty});
                        dis[tx][ty]=dis[u.first][u.second]+1;

                    }
                }
                else if(a[tx][ty]=='.'){
                    if(dis[tx][ty]>dis[u.first][u.second]){
                        q.push({tx,ty});
                        dis[tx][ty]=dis[u.first][u.second];

                    }

                }
            }
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
//        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",&a[i]);
        int st,en;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='$'){
                    st=i;
                    en=j;
                    break;
                }
            }
        }
//        for(int i=0;i<n;i++) printf("%s\n",a[i]);
        bfs(st,en);
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                cout<<dis[i][j]<< " ";
//            }
//            cout<<endl;
//        }
        int ans=1e6;
        for(int i=0;i<n;i++){
            if(dis[i][0]!=1e7){
                ans=min(ans,dis[i][0]);
            }
            if(dis[i][m-1]!=1e7){
                ans=min(ans,dis[i][m-1]);
            }
//            cout<<dis[i][0]<<" "<<dis[i][m-1]<<endl;
        }
        for(int i=0;i<m;i++){
            if(dis[0][i]!=1e7){
                ans=min(ans,dis[0][i]);
            }
            if(dis[n-1][i]!=1e7){
                ans=min(ans,dis[n-1][i]);
            }
        }

        if(ans!=1e6) printf("Case %d: %d\n",cs,ans);
        else printf("Case %d: Impossible\n",cs);
    }
    return 0;
}
/*
Input	Output
1
5 5
*.***
*#*.*
*.$.*
*.*#*
***.*
Case 1: 1
*/
