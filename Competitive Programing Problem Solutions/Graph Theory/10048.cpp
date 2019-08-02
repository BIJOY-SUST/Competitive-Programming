#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >edges;
map<int,vector<int> >weight;
map<int,int>visited;
void BFS(int c1){
    queue<int>q;
    q.push(c1);
    visited[c1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int size=edges[u].size();
        for(int i=0;i<size;i++){
            int v=edges[u][i];
            int max_sound=max(visited[u],weight[u][i]);
            if(max_sound<visited[v]){
                visited[v]=max_sound;
                q.push(v);
            }
        }
    }
}
int main(){
    int C,S,Q,T=0;
    bool flag=true;
    while(1){
        cin>>C>>S>>Q;
        if(C==0&&S==0&&Q==0) break;
        for(int i=0;i<S;i++){
            int c1,c2,d;
            cin>>c1>>c2>>d;
            edges[c1].push_back(c2);
            edges[c2].push_back(c1);
            weight[c1].push_back(d);
            weight[c2].push_back(d);
        }
        if(flag==false) cout<<endl;
        flag=false;
        cout<<"Case #"<<++T<<endl;
        while(Q--){
            for(int j=0;j<=C;j++){
                visited[j]=100009;
            }
            int c1,c2;
            cin>>c1>>c2;
            BFS(c1);
            visited[c2]==100009?cout<<"no path"<<endl:cout<<visited[c2]<<endl;
            visited.clear();
        }
        edges.clear();
        weight.clear();
    }
    return 0;
}
