/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> >edges;
map<int,bool>visited;

void BFS(int a){
    queue<int>q;
    q.push(a);
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int Size = edges[u].size();
        for(int i=0;i<Size;i++){
            int v = edges[u][i];
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
            }
        }
    }
    int c=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            c++;
        }
    }
    cout<<c;
    for(int i=1;i<=n;i++){
        if(!visited[i]) cout<<" "<<i;
    }
    cout<<endl;
}

int main(){
    int u,v;
    while(1){
        cin>>n;
        if(n==0) break;
        edges.resize(n+1);
        while(1){
            cin>>u;
            if(u==0) break;
            while(1){
                cin>>v;
                if(v==0) break;
                edges[u].push_back(v);
            }
        }
        int t,k;
        cin>>t;
        for(int i=1;i<=t;i++){
            cin>>k;
            BFS(k);
        }
        edges.clear();
    }
    return 0;
}

