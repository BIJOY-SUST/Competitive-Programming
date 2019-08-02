#include<bits/stdc++.h>
using namespace std;
int v;
bool isBipartite(int matrix[100][100],int n){
    int color[v];
    queue<int>q;                            ///0 1 0 1
    q.push(n);                              ///1 0 1 0
    memset(color,-1,sizeof(color));         ///0 1 0 1
    color[n]=1;                             ///1 0 1 0
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<v; i++){
            if(matrix[u][i]==1 && color[i]==-1){
                color[i]=1-color[u];
                q.push(i);
            }
            else if(matrix[u][i]==1 && color[u]==color[i]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    cin>>v;
    int matrix[100][100];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>matrix[i][j];
        }
    }
    isBipartite(matrix,0) ? cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}
//4
//0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 0
