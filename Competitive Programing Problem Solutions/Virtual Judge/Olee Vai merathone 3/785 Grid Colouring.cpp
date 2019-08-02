#include<bits/stdc++.h>
#define mx 10000001
#define valid(tx,ty) tx>=0&&tx<r&&ty>=0&&ty<c
using namespace std;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
char grid[50][100];
char ch;
//bool visited[50][100];
void DFS(int a,int b){
//    cout<<"ans"<<endl;
//    visited[a][b]=true;
    for(int i=0;i<4;i++){
        int tx=a+fx[i];
        int ty=b+fy[i];
//        char ch=grid[i][j];
        if(grid[tx][ty]!=ch&&grid[tx][ty]!='X'){
            grid[tx][ty]=ch;
            DFS(tx,ty);
        }
    }
    return;
}
int main(){
    int r=0;
    while(gets(grid[r])){
        if(grid[r][0]=='_'){
//            memset(visited,false,sizeof(visited));
            for(int i=0;i<r;i++){
                int len=strlen(grid[i]);
                for(int j=0;j<len;j++){
                    ch=grid[i][j];
                    if(ch!='X'&&ch!=' '){
                        DFS(i,j);
                    }
                }
            }
            for(int i=0;i<r;i++){
//                puts(grid[i]);
                printf("%s\n",grid[i]);
            }
            puts("_____________________________");
            r=0;
        }
        else r++;
    }
    return 0;
}
