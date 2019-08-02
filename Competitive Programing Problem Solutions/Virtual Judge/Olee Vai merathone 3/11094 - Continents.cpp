#include<bits/stdc++.h>
#define valid(a,b) a>=0&&a<r&&b>=0&&b<c
#define mx 21
using namespace std;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
char grid[mx][mx];
bool visited[mx][mx];
char ch;
int r,c;
int Flood_Fill(int a,int b){
    int temp;
    if(b==c)b=0;else if(b==-1)b=c-1;
    if(valid(a,b)&&grid[a][b]==ch&&!visited[a][b]){
        visited[a][b]=true;
        temp=1;
        for(int i=0;i<4;i++){
            int tx=a+fx[i];
            int ty=b+fy[i];
            temp+=Flood_Fill(tx,ty);
        }
//            else return 0;
//        temp+=Flood_Fill(a,b+1);
//        temp+=Flood_Fill(a+1,b);
//        temp+=Flood_Fill(a-1,b);
        return temp;
    }
    else return 0;
}
//int Flood_Fill(int x, int y){
//    int ret;
//    if(y==c) y=0; else if(y==-1) y=c-1;
//    if(x<0||x>=r||y<0||y>=c||visited[x][y]||grid[x][y] != ch) return 0;
////    if(visited[x][y]) return 0;
////    if(grid[x][y] != ch) return 0;
//    visited[x][y]=1;
//    ret=1;
//    ret+=Flood_Fill(x,y-1);
//    ret+=Flood_Fill(x,y+1);
//    ret+=Flood_Fill(x+1,y);
//    ret+=Flood_Fill(x-1,y);
//    return ret;
//}
int main(){
    while(scanf("%d %d",&r,&c)==2){
        memset(grid,0,sizeof(grid));
        for(int i=0;i<r;i++){
            scanf("%s",&grid[i]);
        }
        memset(visited,false,sizeof(visited));
        int n,m;
        scanf("%d %d",&n,&m);
        ch=grid[n][m];
        Flood_Fill(n,m);
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==ch){
//                    temp=1;
                    int d=Flood_Fill(i,j);
                    if(d>ans) ans=d;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
