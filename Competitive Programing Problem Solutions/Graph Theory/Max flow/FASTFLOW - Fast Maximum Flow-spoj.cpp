/// this implementation is based on ford fulkerson algorithm...
/// it's time complexity -- VE^2 so it's failed to AC this problem
/// Another algo which name is dinic... it's time complexity is -- EV^2... it is the right algo for this problem
/// Below code is DINIC:-
//#include<bits/stdc++.h>
//#define mx             5010
////#define mod            1000000007
////#define pi             2*acos(0.0)
//#define ll             long long int
////#define pp             pair<int,int>
////#define ull            unsigned long long int
////#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
////int biton(int p,int pos){return p=p|(1<<pos);}
////int bitoff(int p,int pos){return p=p&~(1<<pos);}
////bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
////ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
////ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
////ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
//using namespace std;
//ll capacity[mx][mx],par[mx];
//bool vis[mx];
//vector<int>edges[mx];
////vector<int>path;
////vector<vector<int> >paths;
//bool bfs(int n,int start,int finish){
//    bool flag=false;
//    mem(vis,false);
//    mem(par,-1);
//    queue<int>q;
//    q.push(start);
//    vis[start]=true;
//    while(!q.empty()){
//        int u=q.front(); q.pop();
//        for(int i=0;i<edges[u].size();i++){
//            int v=edges[u][i];
//            if(!vis[v]&&capacity[u][v]>0){
//                vis[v]=true;
//                par[v]=u;
//                q.push(v);
//                if(v==finish){
//                    flag=true;
//                    break;
//                }
//            }
//        }
//    }
//    return flag;
//}
//ll FordFulkarson(int n,int start,int finish){
////    path.clear();
////    paths.clear();
//    ll max_flow=0;
//    while(bfs(n,start,finish)){
//        int v=finish;
//        ll flow=1e18;
////        cout<<v<<" ";
//        while(v!=start){
//    //        path.push_back(v);
//            int u = par[v];
////            cout<<v<<" -> "<<u<<" ";
//            flow=min(flow,capacity[u][v]);
//            v=u;
//        }
////        cout<<endl;
////        cout<<"BIJOY "<<flow<<endl;
//    //    path.push_back(start);
//        max_flow+=flow;
//        v=finish;
//        while(v!=start){
//            int u = par[v];
//            capacity[u][v]-=flow;
////            cout<<u<<" "<<v<<" "<<capacity[u][v]<<endl;
//            capacity[v][u]+=flow;
////            cout<<v<<" "<<u<<" "<<capacity[v][u]<<endl;
//            v=u;
//        }
////        reverse(path.begin(),path.end());
////        paths.push_back(path);
////        path.clear();
//    }
//    return max_flow;
//}
//int main(){
////    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
////    ios_base::sync_with_stdio(false); cin.tie(NULL);
//        for(int i=0;i<mx;i++) edges[i].clear();
//        mem(capacity,0);
//        int n,e; scanf("%d%d",&n,&e);
//        for(int i=1;i<=e;i++){
//            int u,v,w;
//            scanf("%d%d%d",&u,&v,&w);
//            if(u!=v){
//                edges[u].push_back(v);
//                edges[v].push_back(u);
//                capacity[u][v]+=w;
//                capacity[v][u]+=w;
//            }
//        }
//        int ans = FordFulkarson(n,1,n);
//        printf("%d\n",ans);
//    return 0;
//}
/*************************************************************************************************************************/
#include<bits/stdc++.h>
#define mx             5010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define ll             long long int
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
ll n,m;
ll level[mx],car[mx];
class data{
public:
    ll from,to,cap,flow;
};
vector<data>edge;
vector<ll>graph[mx];
bool bfs(){
    mem(level,-1);
    queue<ll>q;
    q.push(1);
    level[1]=0;
    while(!q.empty()){
        if(level[n]!=-1) return true;
        ll u=q.front(); q.pop();
        for(ll i=0;i<(ll)graph[u].size();i++){
            ll id=graph[u][i];
            ll v=edge[id].to;
            if(level[v]==-1&&edge[id].flow<edge[id].cap){
                q.push(v);
                level[v]=level[u]+1;
            }
        }
    }
    return false;
}
ll dfs(ll u,ll flow){
    if(u==n) return flow;
    if(flow==0) return 0;
    for(;car[u]<graph[u].size();car[u]++){
        ll id=graph[u][car[u]];
        ll v=edge[id].to;
        if(level[v]==level[u]+1&&edge[id].flow<edge[id].cap){
            ll cur_flow=min(flow,(ll)(edge[id].cap-edge[id].flow));
            ll temp_flow=dfs(v,cur_flow);
            if(temp_flow){
                edge[id].flow+=temp_flow;
                edge[id^1].flow-=temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}
ll dinic(){
    ll max_flow=0;
    while(bfs()){
        mem(car,0);
        while(ll temp_flow=dfs(1,INT_MAX)){
            max_flow+=temp_flow;
            if(temp_flow==0) break;
        }
    }
    return max_flow;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        if(u!=v){
            data ob1={u,v,w,0};
            data ob2={v,u,w,0};
            graph[u].push_back((ll)edge.size());
            edge.push_back(ob1);
            graph[v].push_back((ll)edge.size());
            edge.push_back(ob2);
        }
    }
    ll ans=dinic();
    printf("%lld\n",ans);
    return 0;
}
/**
Input:
4 6
1 2 3
2 3 4
3 1 2
2 2 5
3 4 3
4 3 3

6 9
1 2 10
1 3 10
2 3 2
2 4 4
3 5 9
2 5 8
5 4 6
4 6 10
5 6 10
Output:
5

20
**/
