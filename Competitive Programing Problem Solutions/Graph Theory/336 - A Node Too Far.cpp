#include<bits/stdc++.h>
using namespace std;
map<int,int>visited;

void bfs(int start, map <int,vector<int> >graph){
    queue<int> s;
    s.push(start);
    visited[start]=0;
    while (s.empty() == false) {
        int top = s.front();
        s.pop();
        int size = graph[top].size();
        for(int i=0;i<size;i++){
            int n =graph[top][i];
            if(!visited.count(n)){ //I've already been here.
                visited[n]=visited[top]+1; //Number of moves until here + 1
                s.push(n);
            }
        }
     }
}
int main(){
    int nods,a,b,cases=1;
    while(scanf("%d",&nods) && nods){
             map <int,vector<int> > graph;
             for(int i=0;i<nods;i++){
                     scanf("%d %d",&a,&b);
                     graph[a].push_back(b);
                     graph[b].push_back(a);
             }
             int ttl,start;
             while(scanf("%d %d",&start,&ttl) && (start!=0 || ttl!=0)){
                visited.clear();
                bfs(start,graph);
                map <int,int>::const_iterator itr;
                int result = 0;
                 for(itr = visited.begin(); itr != visited.end(); ++itr){
                        ///cout<<(*itr).first<<" "<<(*itr).second<<endl;
                    if((*itr).second>ttl)++result;
                 }
                 ///cout<<result<<" "<<graph.size()<<" "<<visited.size()<<endl;
                 result += graph.size()-visited.size(); //Aaaaaah!!! The graph could has no connected nodes
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases,result,start,ttl);
                cases++;
             }

    }
 return 0;
}
/* map<int,vector<int> >::const_iterator itr;
             for(itr = graph.begin(); itr != graph.end(); ++itr){ //Imprimir grafo
                cout<<endl<<(*itr).first<<" -> ";
                for (int j = 0; j <(*itr).second.size(); ++j)
                 {
                     cout<<(*itr).second[j]<<" ";
                 }
            }*/
