#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define mx 1010
#define valid(tx,ty) tx>=0&&tx<r&&ty>=0&&ty<c
using namespace std;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
int r,c,ans,x,y;
char arr[mx][mx];
bool visited[mx][mx];
int dis[mx][mx];
void BFS(){
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    memset(visited,false,sizeof(visited));
    memset(dis,0,sizeof(dis));
    visited[x][y]=true;
    while(!q.empty()){
        pair<int,int>p;
        p=q.front();
        q.pop();
//        if(dis[p.first][p.second]>ans){
//            ans=dis[p.first][p.second];
//            x=p.first; y=p.second;
//        }
        for(int i=0;i<4;i++){
            int tx=p.first+fx[i];
            int ty=p.second+fy[i];
            if(arr[tx][ty]=='.'&&valid(tx,ty)&&!visited[tx][ty]){
                visited[tx][ty]=true;
                q.push(make_pair(tx,ty));
                dis[tx][ty]=dis[p.first][p.second]+1;
                if(dis[tx][ty]>ans){
                    ans=dis[tx][ty];
                    x=tx;y=ty;
                }
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d %d",&c,&r);
        for(int j=0;j<r;j++){
            scanf("%s",&arr[j]);
        }
        x=y=-1;
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                if(arr[j][k]=='.'){
                    x=j,y=k;
                    break;
                }
            }
            if(x!=-1) break;
        }
        ans=0;
        BFS();
        ans=0;
        BFS();
        printf("Maximum rope length is %d.\n",ans);
    }
}

