#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >edges;
map<int,int>cost;
map<string,int>mapping;
class data{
public:
    int node,w;
    bool operator<(const data& p)const{
        return w>p.w;
    }
};
int Dijkstra(int start,int End){
    int distance[20001];
    for(int i=0;i<20001;i++){
        distance[i]=INT_MAX;
    }
    priority_queue<data>q;
    data u,v;
    u.node=start,u.w=0;
    q.push(u);
    distance[start]=0;
    while(!q.empty()){
        u=q.top();
        q.pop();
        int uw = distance[u.node];
        for(int i=0;i<edges[u.node].size();i++){
            v.node = edges[u.node][i];
            v.w = cost[u.node][v.node];
            if(distance[v.node]>v.w){
                distance[v.node] = v.w;
                q.push(v);
            }
        }
    }
    return distance[End];
}
int main(){
    int n,Assign=1;
    string start,End;
    string s1,s2,w;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2>>w;
        if(mapping.find(s1)==mapping.end()){
            mapping[s1]=Assign++;
        }
        if(mapping.find(s2)==mapping.end()){
            mapping[s2]=Assign++;
        }
        edges[mapping[s1]].push_back(mapping[s2]);
        edges[mapping[s2]].push_back(mapping[s1]);
        cost[mapping[s1]][mapping[s2]]=w.length();
        cost[mapping[s2]][mapping[s1]]=w.length();
    }
    int d = Dijkstra(mapping[start])
    if(d!=INT_MAX){
        cout<<d<<"\n";
    }
    else{
        cout<<"impossivel\n";
    }
    return 0;
}
