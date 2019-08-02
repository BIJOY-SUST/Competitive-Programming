#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >edges;
map<int,int>visited;
void BFS(int start,int end){
    queue<int>q;
    q.push(start);
    visited[start]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(!visited.count(v)){
                visited[v]=visited[u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    int x,i=1,T=1;
    while(cin>>x){
        for(int k=1;k<=x;k++){
            int y;
            cin>>y;
            edges[i].push_back(y);
            edges[y].push_back(i);
        }
        i++;
        if(i==20){
            int N;
            i=1;
            cin>>N;
            cout<<"Test Set #"<<T<<endl;
            for(int j=1;j<=N;j++){
                int start,end;
                visited.clear();
                cin>>start>>end;
                BFS(start,end);
                 printf("%2d to %2d: %d\n", start, end, visited[end]);
//                cout<<start<<" to "<<end<<": "<<visited[end]<<endl;
            }
            edges.clear();
            T++;
            cout<<endl;
        }
        //cout<<endl;
    }
    return 0;
}
