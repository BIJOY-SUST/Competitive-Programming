/// Time limit solution-BFS
/// Below another  code which will be Optimized
//#include<bits/stdc++.h>
//#define mx             50010
////#define mod            1000000007
////#define pi             2*acos(0.0)
//#define pp             pair<int,int>
////#define ll             long long int
////#define bug(x)         printf("X: %d\n",x)
////#define one(n)         __builtin_popcount(n)
////#define ull            unsigned long long int
////#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
////const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
////const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
////int biton(int n,int pos){return n=n|(1<<pos);}
////int bitoff(int n,int pos){return n=n&~(1<<pos);}
////bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
////ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
////ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
////ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
//using namespace std;
//int money[mx];
//vector<pp >edges[mx];
//void BFS_Dijkstra(int home){
//    for(int i=1;i<mx;i++) money[i]=50001;
//    queue<int>q;
//    q.push(home);
//    money[home]=0;
//    while(!q.empty()){
//        int u=q.front();
//        q.pop();
//        for(int i=0;i<edges[u].size();i++){
//            int v=edges[u][i].first;
//            int w=edges[u][i].second;
//            if(max(w,money[u])<money[v]){
//                money[v]=max(w,money[u]);
//                q.push(v);
//            }
//        }
//    }
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    for(int i=1;i<=t;i++){
//        printf("Case %d:\n",i);
//        memset(money,0,sizeof(money));
//        int n,m;
//        scanf("%d %d",&n,&m);
//        for(int j=1;j<=m;j++){
//            int u,v,w;
//            scanf("%d %d %d",&u,&v,&w);
//            edges[u].push_back({v,w});
//            edges[v].push_back({u,w});
//        }
//        int h; scanf("%d",&h);
//        while(h--){
//            int s,e;
//            scanf("%d%d",&s,&e);
//            BFS_Dijkstra(s);
//            printf("%d\n",money[e]);
//        }
//        for(int i=0;i<=mx;i++){
//            edges[i].clear();
//        }
//    }
//    return 0;
//}
///Using MST&LCA
#include<bits/stdc++.h>
#define mx             50010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
class edge{
public:
    int u,v,w;
    bool operator<(const edge &p)const{
        return w<p.w;
    }
};
vector<edge>e;
int parent[mx];
int level[mx];
int sparse[mx][30];
int dis[mx][30];
int d[mx];
vector<pp >e2[mx];
int find_par(int x){
    if(parent[x]!=x) parent[x]=find_par(parent[x]);
    return parent[x];
}
void mst(int n){
    sort(e.begin(),e.end());
    for(int i=1;i<=n;i++) parent[i]=i;
    int cnt=0,ans=0;
    for(int i=0;i<e.size();i++){
        int pu=find_par(e[i].u);
        int pv=find_par(e[i].v);
//        cout<<pu<<" "<<pv<<" "<<e[i].w<<endl;
        if(pu!=pv){
            parent[pu]=pv;
            cnt++;
            ans+=e[i].w;
            e2[e[i].u].push_back({e[i].v,e[i].w});
            e2[e[i].v].push_back({e[i].u,e[i].w});
//            cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
            if(cnt==n-1) break;
        }
    }
}
void dfs(int from,int uu,int dep){
    parent[uu]=from;
    level[uu]=dep;
    for(int i=0;i<e2[uu].size();i++){
        int vv=e2[uu][i].first;
        int ww=e2[uu][i].second;
        if(vv!=from){
            d[vv]=ww;
//            cout<<uu<<" "<<vv<<" "<<ww<<endl;
            dfs(uu,vv,dep+1);
        }
    }
}
void list_create(int n){
    for(int i=1;i<=n;i++){
        sparse[i][0]=parent[i];
        dis[i][0]=d[i];
//        cout<<d[i]<<endl;
    }
    sparse[1][0]=-1;
    dis[1][0]=0;
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            if(sparse[i][j-1]!=-1){
                sparse[i][j]=sparse[sparse[i][j-1]][j-1];
                dis[i][j]=max(dis[i][j-1],dis[sparse[i][j-1]][j-1]);
            }
        }
    }
}
int lca_query(int n,int p,int q){
    if(level[p]<level[q]) swap(p,q);
    int c,ans=0;
    for(c=0;(1<<c)<=level[p];c++);
    c--;
    for(int i=c;i>=0;i--){
        if(level[p]-(1<<i)>=level[q]){
            ans=max(ans,dis[p][i]);
            p=sparse[p][i];
        }
    }
    if(p==q) return ans;
    for(int i=c;i>=0;i--){
        if(sparse[p][i]!=-1&&sparse[p][i]!=sparse[q][i]){
            ans=max(ans,max(dis[p][i],dis[q][i]));
            p=sparse[p][i]; q=sparse[q][i];
        }
    }
    ans=max(ans,max(d[p],d[q]));
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    int t; scanf("%d",&t);
    int n,m;
    bool flag=true;
    while(scanf("%d%d",&n,&m)==2){
        if(flag==false) printf("\n");
        flag=false;
        mem(parent,-1);
        mem(d,0);
        mem(dis,0);
        mem(level,0);
        mem(sparse,0);
        e.clear();
        for(int i=1;i<=mx;i++) e2[i].clear();
        for(int i=1;i<=m;i++){
            int x,y,z; scanf("%d%d%d",&x,&y,&z);
            edge ob;
            ob.u=x;ob.v=y;ob.w=z;
            e.push_back(ob);
        }
        mst(n);
//        cout<<ans<<endl;
        mem(parent,0);
        dfs(-1,1,0);
        list_create(n);
        int q; scanf("%d",&q);
//        printf("Case %d:\n",cs);
        while(q--){
            int x,y; scanf("%d%d",&x,&y);
            int ans=lca_query(n,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*

*/

