#include<bits/stdc++.h>
using namespace std;
char grid[110][110];
map<pair<int,int>,int> visit;
int n;
int adjx[]={1,1,1,0,-1,-1,-1,0};
int adjy[]={-1,0,1,1,1,0,-1,-1};
void dfs(int a,int b){
    int x,y;
    visit[make_pair(a,b)]=1;
    for(int i=0;i<8;i++){
        x= a+adjx[i];
        y= b+adjy[i];
        //cout<<x<<" "<<y<<endl;
        if(grid[x][y]=='#' && !visit[make_pair(x,y)])
        dfs(x,y);
    }
}
void dfs2(int a,int b){
    int x,y;
    visit[make_pair(a,b)]=1;

    for(int i=0;i<8;i++){
        x= a+adjx[i];
        y= b+adjy[i];
        //cout<<x<<" "<<y<<endl;
        if((grid[x][y]=='*') && !visit[make_pair(x,y)])
        dfs2(x,y);
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        memset(grid,0,sizeof(grid));
        for(int i=1;i<=n;i++){
            //for(int j=1;j<=n;j++){
                cin>>grid[i];
            //}
        }
        visit.clear();
        int cnt=0,cnt2=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(grid[i][j]=='#' && !visit[make_pair(i,j)]){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        visit.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(grid[i][j]=='*' && !visit[make_pair(i,j)]){
                    cnt2++;
                    dfs2(i,j);
                }
            }
        }
        cout<<"Case "<<i<<": "<<cnt<<" "<<cnt2<<endl;
    }
    return 0;
}
