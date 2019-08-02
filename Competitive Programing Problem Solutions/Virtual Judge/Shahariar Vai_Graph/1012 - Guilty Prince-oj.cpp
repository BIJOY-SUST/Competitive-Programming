/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define PI             3.14159265358979323846264338328
//#define PI             acos(-1)
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mx             21
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
char arr[mx][mx];
bool visited[mx][mx];
int ans;
int r,c;
void DFS(int u,int v){
    visited[u][v]=true;
    ans++;
    for(int i=0;i<4;i++){
        int tx=u+fx[i];
        int ty=v+fy[i];
        if(valid(tx,ty)&&!visited[tx][ty]){
            if(arr[tx][ty]=='.') DFS(tx,ty);
        }
    }
}
int main(){
//    freopen("11.txt","r",stdin);
//    freopen("12.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d %d",&c,&r);
        for(int i=0;i<r;i++) scanf("%s",&arr[i]);
        memset(visited,false,sizeof(visited));
        ans=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(arr[i][j]=='@')
                    DFS(i,j);
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
