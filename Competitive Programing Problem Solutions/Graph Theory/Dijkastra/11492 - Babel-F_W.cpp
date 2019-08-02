#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >edges;
int cost[20001][20001];
map<string,int>mapping;

int  F_Warshall(int start,int End,int n){
     for(int k=1;k<n;k++){
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(cost[i][j]>cost[i][k]+cost[k][j]){
                    cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
     }
    //loop(k,n) loop(i,n) loop(j,n) cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
    return cost[start][End];
}
int main(){
    int n,Assign=1;
    string start,End;
    cin>>n;
    cin>>start>>End;
    string s1,s2,w;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2>>w;
        if(mapping.find(s1)==mapping.end()){
            mapping[s1]=Assign++;
            //cout<<mapping[s1]<<endl;
        }
        if(mapping.find(s2)==mapping.end()){
            mapping[s2]=Assign++;
            //cout<<mapping[s2]<<endl;
        }
        edges[mapping[s1]].push_back(mapping[s2]);
        edges[mapping[s2]].push_back(mapping[s1]);
        cost[mapping[s1]][mapping[s2]]=w.length();
        cost[mapping[s2]][mapping[s1]]=w.length();
    }
    for(int i=1;i<Assign;i++){
        for(int j=1;j<Assign;j++){
            if(i==j){
                cost[i][j]=0;
            }
            if(i!=j&&cost[i][j]==0){
                cost[i][j]=1e9;
            }
            if(i!=j&&cost[j][i]==0){
                cost[i][j]=1e9;
            }
        }
    }
    //cout<<Assign<<endl;
    int d = F_Warshall(mapping[start],mapping[End],Assign);
    if(d!=1e9){
        cout<<d<<"\n";
    }
    else{
        cout<<"impossivel\n";
    }
    return 0;
}

