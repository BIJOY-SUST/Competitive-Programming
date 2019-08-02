#include<bits/stdc++.h>
using namespace std;
int v;
bool isBipartite(int matrix[100][100],int n,int color[100]){
    queue<int>q;
    q.push(n);
    color[n]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<v;i++){
            if(matrix[u][i]==1&&color[i]==-1){
                color[i]=1-color[u];
                q.push(i);
            }
            else if(matrix[u][i]==1&&color[i]==color[u]){
                return false;
            }

        }
    }
    return true;
}
bool Bipartite(int matrix[100][100]){
    int color[v];
    memset(color,-1,sizeof(color));
    for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(isBipartite(matrix,i,color)==false){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int matrix[100][100];
    cin>>v;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>matrix[i][j];
        }
    }
    Bipartite(matrix) ? cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}
