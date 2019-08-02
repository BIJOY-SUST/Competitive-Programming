#include<bits/stdc++.h>
#define V 9

using namespace std;
int k;

int min_dis(int vertex[], bool flag[]){
    int min = INT_MAX,point_vertex;
    for (int i = 0; i < V; i++){
        if (flag[i] == false && vertex[i] <= min){
            min = vertex[i], point_vertex = i;
        }
    }
    return point_vertex;
}

int S_P_A(int vertex[]){
    printf("%d",vertex[k]);
}
void Dijkstra(int graph[V][V],int n){
    int vertex[V];
    bool flag[V];
    for(int i=0;i<V;i++){
        vertex[i] = INT_MAX, flag[i] = false;
    }
    vertex[n] = 0;
    for(int i= 0;i<V-1;i++){
        int x = min_dis(vertex, flag);
        flag[x] = true;
        for (int y= 0;y<V;y++)
            if (flag[y]==false && graph[x][y] && vertex[x] != INT_MAX &&vertex[x]+graph[x][y] < vertex[y]){
                vertex[y] = vertex[x] + graph[x][y];
            }
    }
    S_P_A(vertex);
}

int main(){
    int graph[V][V];
    for(int i= 0;i<V;i++){
        for (int j= 0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    scanf("%d",&k);
    Dijkstra(graph, 0);
    return 0;
}
/*
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/
