#include<bits/stdc++.h>
#define mx 10000001
#define valid(tx,ty) tx>=0&&tx<r&&ty>=0&&ty<c
using namespace std;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
typedef pair<int,int> p1;
typedef pair<int,p1> p2;
int r,c;
int Distance[1000][1000];
int grid[1000][1000];
//bool visited[1000][1000];
int Dijkstra(int x1,int y1){
    for(int i=0;i<r;i++)for(int j=0;j<c;j++) Distance[i][j] = 1e9;
    Distance[x1][y1]=grid[x1][y1];
//    pair<int,int>p;
//    memset(visited,false,sizeof(visited));
//    visited[x1][y1]=true;
    priority_queue<p2,vector<p2>,greater<p2> >q;///priority_queue<int,vector<int>,greater<int> >q;
    q.push(make_pair(Distance[x1][y1],p1(x1,y1)));
//    memset(distance,mx,sizeof(distance));
//    memset(Distance,101,sizeof(Distance));

    while(!q.empty()){
        p2 p=q.top();
        q.pop();
        int d=p.first;
        p1 u=p.second;
//        cout<<"mmm"<<endl;
        if(Distance[u.first][u.second]==d){
        for(int i=0;i<4;i++){
            int tx=u.first+fx[i];
            int ty=u.second+fy[i];
//            distance[tx][ty]=grid[tx][ty];
            if(valid(tx,ty)){
                int k=grid[tx][ty]+Distance[u.first][u.second];
                if(Distance[tx][ty]>k){
                    Distance[tx][ty]=k;
                    q.push(make_pair(k,p1(tx,ty)));
                }
            }
        }
        }
    }
    return Distance[r-1][c-1];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        memset(grid,0,sizeof(grid));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%d",&grid[i][j]);
            }
        }
//        cout<<"bbb"<<endl;
        int ans=Dijkstra(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
