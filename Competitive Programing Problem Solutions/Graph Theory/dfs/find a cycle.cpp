/*The structure of the class is as follows
which contains an integer V denoting the no
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};*/
/*You are required to complete this method*/
/*The structure of the class is as follows
which contains an integer V denoting the no
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};*
/*You are required to complete this method*/

bool DFS(bool *visited,int vertex,int parent,list<int>* adj){
    visited[vertex]=true;
    list<int>:: iterator i;
    for(i=adj[vertex].begin();i!=adj[vertex].end();++i){
        if(!visited[*i]){
            if(DFS(visited,*i,vertex,adj)){
                return true;
            }
        }
        else if(*i!=parent){
            return true;
        }
    }
    return false;
}

bool Graph :: isCyclic(){
    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(DFS(visited,i,-1,adj)){
                return true;
            }
        }
    }
    return false;
}
