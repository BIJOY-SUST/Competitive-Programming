#include<bits/stdc++.h>
using namespace std;
int representative[5005];
int find_parent(int x){
    if(representative[x]!=x) representative[x]=find_parent(representative[x]);
    return representative[x];
}
int main(){
    int n,m;
    string s,ss1,ss2;
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        map<string,int>creatures;
        map<int,int>max_cre;
        for(int i=1;i<=n;i++){
            cin>>s;
            creatures[s]=i;
            representative[i]=i;
        }
        for(int i=1;i<=m;i++){
            cin>>ss1>>ss2;
            int u=find_parent(creatures[ss1]);
            int v=find_parent(creatures[ss2]);
            representative[u]=v;
        }
        int L_A_C=0;
        for(int i=1;i<=n;i++){
            representative[i]=find_parent(i);
            max_cre[representative[i]]++;
            L_A_C=max(L_A_C,max_cre[representative[i]]);
        }
        cout<<L_A_C<<endl<<endl;
    }
    return 0;
}
