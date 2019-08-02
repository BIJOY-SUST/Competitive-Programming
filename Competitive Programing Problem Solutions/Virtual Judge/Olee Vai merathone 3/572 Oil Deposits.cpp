#include<bits/stdc++.h>
#define valid(tx,ty) tx>=0&&tx<r&&ty>=0&&ty<c
using namespace std;
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
char str[101][101];
bool visited[101][101];
int r,c;
void DFS(int a,int b){
    visited[a][b]=true;
    for(int i=0;i<8;i++){
//        cout<<"BIJOY"<<endl;
        int tx=a+fx[i];
        int ty=b+fy[i];
        if(str[tx][ty]=='@'&&!visited[tx][ty]&&valid(tx,ty)){
            DFS(tx,ty);
//            cout<<"BIJOY"<<endl;
        }
    }
    return;
}
int main(){
    while(scanf("%d %d",&r,&c)==2&&r!=0){
        memset(str,0,sizeof(str));
        for(int i=0;i<r;i++){
            scanf("%s",&str[i]);
        }
        int ans=0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                char ch=str[i][j];
                if(!visited[i][j]&&ch=='@'){
//                        cout<<"BIJOY"<<endl;
                    DFS(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
