#include<bits/stdc++.h>
using namespace std;
int v;
bool isBipartite(int matrix[100][100],int n,int color[]){
    queue<int>q;                            ///0 1 0 1
    q.push(n);                              ///1 0 1 0
    color[n]=1;                             ///0 1 0 1
    while(!q.empty()){                      ///1 0 1 0
        int u=q.front();
        q.pop();
        for(int i=0;i<v;i++){
            if(matrix[u][i]==1&&color[i]==-1){
                color[i]=1-color[u];
                q.push(i);
            }
            else if(matrix[u][i]==1&&color[u]==color[i]){
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
        if (color[i] == -1){
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
