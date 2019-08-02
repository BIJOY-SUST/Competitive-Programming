#include<bits/stdc++.h>
using namespace std;
int n,m;
int order[1000][1000];
map<int,int>indegree;
map<int,int>taken;
void T_SORT(){
    vector<int>task;
    int j;
    bool flag=true;
    for(int i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(!taken[j] && !indegree[j]){
                taken[j]=1;
                task.push_back(j);
                for(int k=1;k<=n;k++){
                    if(!taken[k]&&order[j][k]) indegree[k]--;
                }
                break;
            }
        }
        if(j==n+1) flag=false;
    }
    if(flag==true){
        vector<int>::iterator it;
        for(it=task.begin();it!=task.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
        task.clear();
    }
    else{
        cout<<"This is no solution"<<endl;
        task.clear();
    }
}
int main(){
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++){
            indegree[i]=0;
            taken[i]=0;
        }
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            order[u][v]=1;
            indegree[v]++;
        }
        T_SORT();
        memset(order,0,sizeof(order));
        indegree.clear();
        taken.clear();
    }
    return 0;
}
