/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mx             101
//#define mod            1000000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
map<int,vector<int> >edges;
int dis1[mx];
int dis2[mx];
bool visited[mx];
void bfs(int s,int *dis){
    queue<int>q;
    q.push(s);
    memset(visited,false,sizeof(visited));
    visited[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(!visited[v]){
                dis[v]=dis[u]+1;
                visited[v]=true;
                q.push(v);
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
    for(int tc=1;tc<=t;tc++){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        memset(dis1,0,sizeof(dis1));
        memset(dis2,0,sizeof(dis2));
        int ans=0,s,f;
        scanf("%d %d",&s,&f);
        bfs(s,dis1);
        bfs(f,dis2);
        for(int i=0;i<n;i++){
            ans=max(ans,dis1[i]+dis2[i]);
        }
        printf("Case %d: %d\n",tc,ans);
        for(int i=0;i<n;i++){
            edges[i].clear();
        }
    }
    return 0;
}

