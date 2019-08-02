#include<bits/stdc++.h>
using namespace std;
int tx[] = {1,-1,0,0};
int ty[] = {0,0,-1,1};
int grid[1001][1001];
int d_tance[1001][1001];
int R,C,rows;
void BFS(int s1,int e1,int s2,int e2){
    queue<pair<int,int> >q;
    q.push(make_pair(s1,e1));
    memset(d_tance,100,sizeof(d_tance));
    d_tance[s1][e1]=0;
    while(!q.empty()){
        pair<int,int>top;
        top = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = top.first+tx[i];
            int ny = top.second+ty[i];
            if(nx>=0&&nx<R&&ny>=0&&ny<C&&grid[nx][ny]!='*'&&d_tance[top.first][top.second]+1<d_tance[nx][ny]){
                q.push(make_pair(nx,ny));
                d_tance[nx][ny] = d_tance[top.first][top.second]+1;
            }
        }
    }
    cout<<d_tance[s2][e2]<<endl;
}
int main(){
    while(cin>>R>>C){
        if(R==0&&C==0){
            break;
        }
        memset(grid,0,sizeof(grid));
        cin>>rows;
        for(int i=1;i<=rows;i++){
            int c_row,c_bombs,c_no;
            cin>>c_row>>c_bombs;
            for(int j=1;j<=c_bombs;j++){
                cin>>c_no;
                grid[c_row][c_no]='*';
            }
        }
        int s1,e1,s2,e2;
        cin>>s1>>e1;
        cin>>s2>>e2;
        BFS(s1,e1,s2,e2);
    }
    return 0;
}
