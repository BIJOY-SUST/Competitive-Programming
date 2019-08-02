#include<bits/stdc++.h>
using namespace std;
map<string,vector<string> >edges;
map<string,string>connect;
map<string,int>visited;
int BFS(string s3,string s4){
    queue<string>q;
    q.push(s3);
    visited[s3]=0;
    while(!q.empty()){
        string u=q.front();
        q.pop();
        if(u==s4){
            return visited[u];
        }
        for(int i=0;i<edges[u].size();i++){
            string v = edges[u][i];
            if(visited[v]==-1){
                visited[v]=visited[u]+1;
                connect[v]=u;
                q.push(v);
            }
        }
    }
    return -1;
}
void print_route(string s3,string s4){
    if(s4==s3){
        return;
    }
    print_route(s3,connect[s4]);
    cout<<connect[s4]<<" "<<s4<<endl;
}
int main(){
    int N;
    bool flag = true;
    while(cin>>N){
        edges.clear();
        visited.clear();
        connect.clear();
        string s1,s2;
        for(int i=0;i<N;i++){
            cin>>s1>>s2;
            edges[s1].push_back(s2);
            edges[s2].push_back(s1);
            visited[s1]=-1;visited[s2]=-1;
        }
        string s3,s4;
        cin>>s3>>s4;
        if(!flag){
            cout<<endl;
        }
        flag = false;
        int r_val = BFS(s3,s4);
        if(r_val!=-1){
            print_route(s3,s4);
        }
        else{
            cout<<"No route"<<endl;
        }
    }
    return 0;
}
