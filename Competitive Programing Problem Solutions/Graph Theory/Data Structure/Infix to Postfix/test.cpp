




































































































//#include<bits/stdc++.h>
//using namespace std;
//map<int,vector<int> >edges;
//int visited[101];
//int weight[101];
//int ans,node;
//void DFS(int u){
//    int d=0,node_value;
//    bool r_node=false;
//    for(int i=0;i<edges[u].size();i++){
//        int v=edges[u][i];
//        if(!visited[v]){
//            if(weight[v]>d){
//                d=weight[v];
//                r_node=true;
//                node_value=v;
//            }
//        }
//    }
//    if(r_node){
//        ans+=d;
//        node=node_value;
//        DFS(node_value);
//    }
//    return;
//}
//int main(){
//    int t;
//    cin>>t;
//    for(int i=1;i<=t;i++){
//        int n,m;
//        ans=0;
//        memset(visited,0,sizeof(visited));
//        memset(weight,-1,sizeof(weight));
//        scanf("%d %d",&n,&m);
//        for(int i=0;i<n;i++){
//            int k;
//            scanf("%d",&k);
//            weight[i]=k;
//        }
//        for(int i=0;i<m;i++){
//            int u,v;
//            scanf("%d %d",&u,&v);
//            edges[u].push_back(v);
//        }
//        DFS(0);
//        printf("Case %d: %d %d\n",i,ans,node);
//        edges.clear();
//    }
//    return 0;
//}
