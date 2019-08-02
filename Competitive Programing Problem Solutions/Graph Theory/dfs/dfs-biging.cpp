/* You have to complete this function
which prints out the depth first level traversal of the
graph starting from node s
the vector<int> g[i] represent the adjacency
list of the ith node of the graph
 */
void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s]=true;
    cout<<s<<' ';
    for(int i=0;i<g[s].size();++i)
        if(!vis[ g[s][i] ])
            dfs(g[s][i], g, vis);
}
