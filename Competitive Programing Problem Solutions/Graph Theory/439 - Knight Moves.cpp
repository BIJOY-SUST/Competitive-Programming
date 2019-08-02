#include<bits/stdc++.h>
using namespace std;
int tx[]={2,2,-2,-2,-1,1,-1,1};
int ty[]={1,-1,1,-1,-2,-2,2,2};
int visited[1001][1001];
string s1,s2;
string s[8][8]={{"a1","b1","c1","d1","e1","f1","g1","h1"},
                {"a2","b2","c2","d2","e2","f2","g2","h2"},
                {"a3","b3","c3","d3","e3","f3","g3","h3"},
                {"a4","b4","c4","d4","e4","f4","g4","h4"},
                {"a5","b5","c5","d5","e5","f5","g5","h5"},
                {"a6","b6","c6","d6","e6","f6","g6","h6"},
                {"a7","b7","c7","d7","e7","f7","g7","h7"},
                {"a8","b8","c8","d8","e8","f8","g8","h8"}};
void BFS(int x1,int y1,int x2,int y2){
    queue<pair<int,int> >q;
    q.push(make_pair(x1,y1));
    memset(visited,100,sizeof(visited));
    visited[x1][y1]=0;
    while(!q.empty()){
        pair<int,int>top;
        top = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nx=top.first+tx[i];
            int ny=top.second+ty[i];
            if(nx>=0&&nx<8&&ny>=0&&ny<8&&visited[top.first][top.second]+1<visited[nx][ny]){
                visited[nx][ny]=visited[top.first][top.second]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    //printf("To get from %2d to %2d takes %2d knight moves.\n",x2,y2,visited[x2][y2]);
    cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<visited[x2][y2]<<" knight moves."<<endl;
}
int main(){
    while(cin>>s1>>s2){
        int x1,y1,x2,y2;
        bool flag1 = true,flag2 = true;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(s[i][j]==s1){
                    x1=i;y1=j;
                    flag1 = false;
                    break;
                }
            }
            if(flag1==false){
                break;
            }
        }
        for(int h=0;h<8;h++){
            for(int k=0;k<8;k++){
                if(s[h][k]==s2){
                    x2=h;y2=k;
                    flag2 = false;
                    break;
                }
            }
            if(flag2==false){
                break;
            }
        }
        //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        BFS(x1,y1,x2,y2);
    }
    return 0;
}
