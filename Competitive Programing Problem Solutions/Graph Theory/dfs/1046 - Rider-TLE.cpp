#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define pp             pair<int,int>
//#define ll             long long int
#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<m
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//template< class T > inline T SQR(T a) {return ((a)*(a));}
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
char a[11][11];
int n,m;
int dis[11][11];
int bfs(int i,int j,int u,int v){
    //mem(dis,100);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) dis[i][j]=100001;
    queue<pp >q;
    q.push({i,j});
    dis[i][j]=0;
    while(!q.empty()){
        pp x=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int tx=x.first+fx[i];
            int ty=x.second+fy[i];
            if(valid(tx,ty)){
                if(dis[tx][ty]>dis[x.first][x.second]+1){
                    dis[tx][ty]=dis[x.first][x.second]+1;
                    q.push({tx,ty});
                }
            }
        }
    }
    //cout<<dis[u][v];
    return dis[u][v];
}
int per_square(int u,int v){
    int dd=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //bug(j);
            if(a[i][j]!='.'){
                //bug(j);
                if(i==u&&j==v) continue;
                else{
                    //bug(j);
                    int num=a[i][j]-'0';
                    int cc=bfs(i,j,u,v);
                    if(cc==100001){
                        return cc;
                    }
                    else{
                        //dd+=cc;
//                        int rem=cc%num;
//                        int vag=cc/num;
//                        cc=vag+rem;
                        cc=(cc+num-1)/num;
                        dd+=cc;
                    }
                }
            }
        }
    }
    return dd;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){

        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",&a[i]);
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                cout<<a[i][j];
//            }
//            cout<<endl;
//        }
        int ans=1000001;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cc=per_square(i,j);
                if(cc==100001){
                    continue;
                }
                else{
                //cout<<cc<<endl;
                    ans=min(ans,cc);
                }
            }
        }
        if(ans!=1000001) printf("Case %d: %d\n",cs,ans);
        else{
            printf("Case %d: -1\n",cs);
        }
    }
    return 0;
}
/*

*/
