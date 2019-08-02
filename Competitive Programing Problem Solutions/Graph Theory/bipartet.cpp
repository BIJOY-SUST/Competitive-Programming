///practice.geeksforgeeks.org/user-profile.php?user=BIJOY_SUST
/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
bool isBipartite(int g[MAX][MAX],int v){
    int n=0,color[v];
    queue<int>q;                            ///0 1 0 1
    q.push(n);                              ///1 0 1 0
    memset(color,-1,sizeof(color));         ///0 1 0 1
    color[n]=1;                             ///1 0 1 0
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ///if(g[u][u]==1) return false;
        for(int i=0; i<v; i++){
            if(g[u][i]==1 && color[i]==-1){
                color[i]=1-color[u];
                q.push(i);
            }
            else if(g[u][i]==1 && color[u]==color[i]){
                return false;
            }
        }
    }
    return true;
}
