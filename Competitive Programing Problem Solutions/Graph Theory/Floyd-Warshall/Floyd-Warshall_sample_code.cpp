#include<bits/stdc++.h>/// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
#define INF 999999
int distance[101][101];
int graph[101][101];
int V,E;
void Print_Solution(){
    printf("Following matrix shows the shortest distances between every pair of vertices \n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(distance[i][j]==INF) printf("%7s","INF");
            else printf ("%7d", distance[i][j]);
        }
        printf("\n");
    }
}
void Floyd_Warshall (){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            distance[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(distance[i][k]+distance[k][j]<distance[i][j]){/// If vertex k is on the shortest path from i to j,...
                    distance[i][j]=distance[i][k]+distance[k][j];///...then update the value of distance[i][j]
                }
            }
        }
    }
    Print_Solution();
}
int main(){
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
//    int graph[V][V] = { {0,   5,  INF, 10},
//                        {INF, 0,   3, INF},
//                        {INF, INF, 0,   1},
//                        {INF, INF, INF, 0}
//                      };
    scanf("%d %d",&V,&E);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j) graph[i][j]=0;
            else graph[i][j]=INF;
        }
    }
    for(int i=1;i<=E;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=w;
    }
    Floyd_Warshall();
    return 0;
}
