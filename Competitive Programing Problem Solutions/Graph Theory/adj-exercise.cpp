#include<bits/stdc++.h>
using namespace std;
vector<int>edges[100000];
vector<int>cost_i[100000];
vector<int>cost_o[100000];
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        cost_o[x].push_back(y);
        cost_i[y].push_back(x);
    }
    cout<<"Number of Nodes and its Elements:"<<endl;
    for(int i=1;i<=n;i++){
        int size = edges[i].size();
        cout<<"Node NO : "<<i<<" Total Nodes : "<<size<<" Elements : ";
        for(int j=0;j<size;j++){
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Number of Indegree Nodes and its Elements:"<<endl;
    for(int i=1;i<=n;i++){
        int size = cost_i[i].size();
        cout<<"Node NO : "<<i<<" Total Nodes : "<<size<<" Elements : ";
        for(int j=0;j<size;j++){
            cout<<cost_i[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Number of Outdegree Nodes and its Elements:"<<endl;
    for(int i=1;i<=n;i++){
        int size = cost_o[i].size();
        cout<<"Node NO : "<<i<<" Total Nodes : "<<size<<" Elements : ";
        for(int j=0;j<size;j++){
            cout<<cost_o[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
