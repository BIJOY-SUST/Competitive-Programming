#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define llu            unsigned long long int
#define mx             110
//#define mod            100000007
//const long long inf =  1e15;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//-----------------------------------------------------
//-----------------------Bitmask-----------------------
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//-----------------------------------------------------
using namespace std;
vector<pair<int,int> >edges[mx];
bool dir[mx][mx];
bool vis[mx];
ll ans1,ans2;
//vector<int>v;
int par[mx];
void dfs(int u){
    vis[u]=true;
    //v.push_back(u);
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i].first;
        if(par[u]==v&&vis[v]) continue;
        else if(par[u]!=v&&!vis[v]){
            if(dir[u][v]){
                par[v]=u;
                dfs(v);
            }
            else{
                ans1+=edges[u][i].second;
                par[v]=u;
                dfs(v);
            }
        }
        else if(par[u]!=v&&v==1&&vis[v]){
            if(dir[u][v]){
                par[u]=v;
                return;
            }
            else{
                ans1+=edges[u][i].second;
                par[v]=u;
                return;
            }
        }
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        memset(dir,false,sizeof(dir));
        for(int i=0;i<n;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edges[u].push_back(make_pair(v,w));
            edges[v].push_back(make_pair(u,w));
            dir[u][v]=true;
        }
        memset(vis,false,sizeof(vis));
        ans1=0;
//        vis[1]=true;
        dfs(1);
        ll b1=ans1;
        //printf("%d\n",ans1);
//        for(int i=0;i<v.size();i++){
//            cout<<v[i]<<'\n';
//        }
        memset(par,0,sizeof(par));
        memset(vis,false,sizeof(vis));
        //cout<<edges[1][0].first<<edges[1][1].first<<endl;
        ans1=0;
        for(int i=1;i<=n;i++){
            if(edges[i].size()!=0)
                reverse(edges[i].begin(),edges[i].end());
        }
        //cout<<edges[1][0].first<<edges[1][1].first<<endl;
        dfs(1);
        //printf("%d\n",ans1);
        ll b2=ans1;
        printf("Case %d: %lld\n",cs,min(b1,b2));
        for(int i=1;i<=n;i++){
            if(edges[i].size()!=0)
                reverse(edges[i].begin(),edges[i].end());
        }
        for(int i=1;i<=mx;i++) edges[i].clear();
        memset(par,0,sizeof(par));


    }
    return 0;
}
/*
Sample Input
4

3
1 3 1
1 2 1
3 2 1

3
1 3 1
1 2 5
3 2 1

6
1 5 4
5 3 8
2 4 15
1 6 16
2 3 23
4 6 42

4
1 2 9
2 3 8
3 4 7
4 1 5
Sample Output
Case 1: 1
Case 2: 2
Case 3: 39
Case 4: 0
*/
