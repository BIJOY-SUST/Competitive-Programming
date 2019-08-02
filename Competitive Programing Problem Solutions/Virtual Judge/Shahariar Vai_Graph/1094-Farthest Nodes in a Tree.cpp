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
#define mx             30001
//#define mod            1000000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
vector<pair<int,int> >edges[mx];
int st;
long long int ans;
bool visited[mx];
void DFS(int u,long long int dis){
    visited[u]=true;
    if(dis>ans){
        ans=dis;
        st=u;
    }
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i].first;
        int w=edges[u][i].second;
        if(!visited[v]) DFS(v,dis+w);
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edges[u].push_back(make_pair(v,w));
            edges[v].push_back(make_pair(u,w));
        }
        ans=0;
        memset(visited,false,sizeof(visited));
        DFS(0,0);
        //cout<<st<<" "<<ans<<endl;
        ans=0;
        memset(visited,false,sizeof(visited));
        DFS(st,0);
        printf("Case %d: %d\n",tc,ans);
        for(int i=0;i<n;i++){
            edges[i].clear();
        }
    }
    return 0;
}
