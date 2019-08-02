#include<bits/stdc++.h>

using namespace std;
#define MAX 10000001
int isCat[MAX];
bool visited[MAX];
vector<vector<int> > graph(MAX);
int n , m , ans = 0;
void dfs(int u , int sum_cat)
{
    int sum = 0;
    visited[u] = true;
    if(sum_cat > m)
        return;

    bool ok = false;
    for(int v = 0 ; v < graph[u].size() ; v++)
    {
        if(!visited[graph[u][v]])
        {
            cout << u << " " << v << endl;
            isCat[graph[u][v]] ? sum = sum_cat + 1 : sum = 0;
            dfs(graph[u][v] , sum);
            ok = true;
        }
    }
    if(!ok)
        ans++;
}
int main()
{
    int x , y;
    cin >> n >> m;//cout << n << m;
    for(int i = 1 ; i <= n ; i++)
        cin >> isCat[i];

    for(int i = 1; i < n ; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1 , isCat[1]);
    cout << ans<<endl;
    return 0;
}
