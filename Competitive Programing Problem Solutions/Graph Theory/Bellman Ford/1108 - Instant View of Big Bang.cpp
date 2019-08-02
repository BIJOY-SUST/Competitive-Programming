#include<bits/stdc++.h>
#define mx             2010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define pp             pair<int,int>
#define ll             long long int
//#define me             printf("BIJOY\n");
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
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
vector<pp >edges[mx];
vector<int>path;
int dd[mx];
bool vis[mx];
void dfs(int u){
    vis[u]=true;
    path.push_back(u);
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i].first;
        if(!vis[v]) dfs(v);
    }
}
bool B_F(int n){
    for(int i=0;i<mx;i++) dd[i]=1000001;
//    dd[0]=0;
    bool f=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int h=0;h<edges[j].size();h++){
                int v=edges[j][h].first;
                int w=edges[j][h].second;
                if(dd[j]+w<dd[v]){
                    dd[v]=dd[j]+w;
                    if(i==n-1){
                        f=true;
                        if(!vis[j]) dfs(j);
                    }
                }
            }
        }
    }
    return f;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int s1,s2,w;
        mem(vis,false);
        path.clear();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int j=0;j<m;j++){
            scanf("%d %d %d",&s1,&s2,&w);
            edges[s2].push_back(make_pair(s1,w));
        }
        bool flag=B_F(n);
        if(flag){
            printf("Case %d:",i);
            sort(path.begin(),path.end());
            for(int i=0;i<path.size();i++){
                printf(" %d",path[i]);
            }
            printf("\n");
        }
        else{
            printf("Case %d: impossible\n",i);
        }
        path.clear();
        for(int i=0;i<=mx;i++) edges[i].clear();
    }
    return 0;
}



///কিছু পরিবর্তন নিয়ে আরেকটি Solution:
//#include<bits/stdc++.h>
//#define mx             2010
////#define mod            1000000007
////#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
////#define me             printf("BIJOY\n");
////#define one(n)         __builtin_popcount(n)
////#define ull            unsigned long long int
////#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
////const int fx[]={+1,-1,+0,+0};
////const int fy[]={+0,+0,+1,-1};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
////const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
////const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
////int biton(int n,int pos){return n=n|(1<<pos);}
////int bitoff(int n,int pos){return n=n&~(1<<pos);}
////bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
////template< class T > inline T SQR(T a) {return ((a)*(a));}
////template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
////template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
////template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
////template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
////template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
//using namespace std;
//vector<int>edges[mx];
//ll Distance[mx];
//int cost[mx][mx];
//vector<int>path;
//bool vis[mx];
//void dfs(int u){
//    vis[u]=true;
//    path.push_back(u);
//    for(int i=0;i<edges[u].size();i++){
//        int v=edges[u][i];
//        if(!vis[v]) dfs(v);
//    }
//}
//bool B_F(int n){
//    for(int i=0;i<mx;i++) Distance[i]=2000010;
//    bool f=false;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            for(int h=0;h<edges[j].size();h++){
//                int v=edges[j][h];
//                if(Distance[j]+cost[j][v]<Distance[v]){
//                    Distance[v]=Distance[j]+cost[j][v];
//                    if(i==n-1){
//                        f=true;
//                        if(!vis[j]) dfs(j);
//                    }
//                }
//            }
//        }
//    }
//    return f;
//}
//int main(){
////    freopen("Input.txt","r",stdin);
////    freopen("Output.txt","w",stdout);
//    int t;
//    scanf("%d",&t);
//    for(int i=1;i<=t;i++){
//        int s1,s2,w;
//        mem(cost,0);
//        mem(vis,false);
//        int n,m;
//        scanf("%d %d",&n,&m);
//        for(int j=0;j<m;j++){
//            scanf("%d %d %d",&s1,&s2,&w);
//            edges[s2].push_back(s1);
//            cost[s2][s1]=w;
//        }
//        bool flag=B_F(n);
//        if(flag){
//            printf("Case %d:",i);
//            sort(path.begin(),path.end());
//            for(int i=0;i<path.size();i++){
//                printf(" %d",path[i]);
//            }
//            printf("\n");
//        }
//        else{
//            printf("Case %d: impossible\n",i);
//        }
//        path.clear();
//        for(int i=0;i<=mx;i++) edges[i].clear();
//    }
//    return 0;
//}
