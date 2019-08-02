#include<bits/stdc++.h>
#define mx             110
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
#define pp             pair<int,int>
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
int par[mx],dis[mx];
bool vis[mx][mx];
vector<pp >edges[mx];
int cnt;
bool bfs(int n,int start,int finish){
    for(int i=1;i<mx;i++) dis[i]=1e9;
    dis[start]=0;
    bool flag=false;
    mem(par,-1);
    priority_queue<pp >q;
    q.push({0,start});
    while(!q.empty()){
//        cout<<"BIJOY"<<endl;
        pp u=q.top(); q.pop();
        for(int i=0;i<edges[u.second].size();i++){
            pp v=edges[u.second][i];
            if(vis[u.second][v.second]) continue;
            if(vis[v.second][u.second]){
                if(dis[u.second]-v.first<dis[v.second]){
                    par[v.second]=u.second;
                    dis[v.second]=dis[u.second]-v.first;
                    q.push({-dis[v.second],v.second});
                    if(v.second==finish){
                        flag=true;
                        break;
                    }
                }
            }
            else if(dis[u.second]+v.first<dis[v.second]){
                par[v.second]=u.second;
                dis[v.second]=dis[u.second]+v.first;
                q.push({-dis[v.second],v.second});
                if(v.second==finish){
                    flag=true;
                    break;
                }
            }
        }
    }
    return flag;
}
int FordFulkarson(int n,int start,int finish){
    int max_flow=0;
    while(bfs(n,start,finish)){
//                cout<<"BIJOY"<<endl;
        int v=finish;
//        cout<<dis[finish]<<endl;
        max_flow+=dis[finish];
//        cout<<dis[finish]<<endl;
        v=finish;
        while(v!=start){
            int u = par[v];
            vis[u][v]=true;
            v=u;
        }
//        cout<<"BIJOY"<<endl;
        cnt++;
        if(cnt==2) return max_flow;
    }
    return max_flow;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        cnt=0;
        for(int i=0;i<mx;i++) edges[i].clear();
        mem(vis,false);
        int start=1,finish=n,e;
        scanf("%d",&e);
        for(int i=1;i<=e;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back({w,v});
            edges[v].push_back({w,u});
        }
//        cout<<"BIJOY"<<endl;
        int ans = FordFulkarson(n,start,finish);
        if(cnt==2){
            printf("%d\n",ans);
        }
        else{
            printf("Back to jail\n");
        }
    }
    return 0;
}
/**
Think this test case
Input:
6
8
1 2 1
2 3 1
3 6 1
1 4 100
4 5 100
5 6 100
1 3 10
2 6 10
Output:
22
**/

















/*************************************************************************************/
//#include<bits/stdc++.h>
//#define mx             110
////#define mod            1000000007
////#define pi             2*acos(0.0)
////#define ll             long long int
//#define pp             pair<int,int>
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
//int par[mx],dis[mx];
//bool vis[mx][mx];
//vector<pp >edges[mx];
//int cnt;
//bool bfs(int n,int start,int finish){
//    for(int i=1;i<mx;i++) dis[i]=1e9;
//    dis[start]=0;
//    bool flag=false;
//    mem(par,-1);
//    priority_queue<pp >q;
//    q.push({0,start});
//    while(!q.empty()){
////        cout<<"BIJOY"<<endl;
//        pp u=q.top(); q.pop();
//        for(int i=0;i<edges[u.second].size();i++){
//            pp v=edges[u.second][i];
//            if(vis[u.second][v.second]) continue;
//            if(dis[u.second]+v.first<dis[v.second]){
//                par[v.second]=u.second;
//                dis[v.second]=dis[u.second]+v.first;
//                q.push({-dis[v.second],v.second});
//                if(v.second==finish){
//                    flag=true;
//                    break;
//                }
//            }
//        }
//    }
//    return flag;
//}
//int FordFulkarson(int n,int start,int finish){
//    int max_flow=0;
//    while(bfs(n,start,finish)){
////                cout<<"BIJOY"<<endl;
//        int v=finish;
////        cout<<dis[finish]<<endl;
//        max_flow+=dis[finish];
//        v=finish;
//        while(v!=start){
//            int u = par[v];
//            vis[u][v]=true;
//            for(int i=0;i<edges[v].size();i++){
//                int v2=edges[v][i].second;
//                if(v2!=u) continue;
//                edges[v][i].first*=-1;
//            }
////            cout<<u<<" "<<v<<endl;
//            v=u;
//        }
////        cout<<"BIJOY"<<endl;
//        cnt++;
//        if(cnt==2) return max_flow;
//    }
//    return max_flow;
//}
//int main(){
////    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
////    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    int n;
//    while(scanf("%d",&n)==1){
//        if(n==0) break;
//        cnt=0;
//        for(int i=0;i<mx;i++) edges[i].clear();
//        mem(vis,false);
//        int start=1,finish=n,e;
//        scanf("%d",&e);
//        for(int i=1;i<=e;i++){
//            int u,v,w;
//            scanf("%d%d%d",&u,&v,&w);
//            edges[u].push_back({w,v});
//            edges[v].push_back({w,u});
//        }
////        cout<<"BIJOY"<<endl;
//        int ans = FordFulkarson(n,start,finish);
//        if(cnt==2){
//            printf("%d\n",ans);
//        }
//        else{
//            printf("Back to jail\n");
//        }
//    }
//    return 0;
//}
//*
//Input:
//3
//4
//1 3 10
//2 1 20
//3 2 50
//
//Output:
//
//*/
//
//
