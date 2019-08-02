#include<bits/stdc++.h>
using namespace std;
int tx[] = {1,-1,0,0};
int ty[] = {0,0,-1,1};
int r,c,x2,y2,mx = 0;
char w[1000][1000];///w = Input Format.........
int d[1000][1000];///d = Distance.............
void BFS(int x,int y){
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    memset(d,100,sizeof(d));
    d[x][y] = 0;
    while(!q.empty()){
        pair<int,int>top;
        top = q.front();
        q.pop();
        if(d[top.first][top.second]>mx){
            mx = d[top.first][top.second];
            x2 = top.first; y2 = top.second;
        }
        for(int i=0;i<4;i++){
            int nx = top.first+tx[i];
            int ny = top.second+ty[i];
            if(nx>=0&&nx<r&&ny>=0&&ny<c&&w[nx][ny]=='.'&&d[top.first][top.second]+1<d[nx][ny]){
                q.push(make_pair(nx,ny));
                d[nx][ny] = d[top.first][top.second]+1;
            }
        }
    }
}
int main(){
    int x1,y1,cc=0;
    cin>>r>>c;
    swap(r,c);
    for(int i=0;i<r;i++){
        cin>>w[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(w[i][j]=='.'){
                x1 = i; y1 = j; cc++;
            }
        }
    }
    BFS(x1,y1);
    mx = 0;
    BFS(x2,y2);
    if(cc==1){
        mx = 0;
    }
    cout<<mx<<endl;
    return 0;
}
