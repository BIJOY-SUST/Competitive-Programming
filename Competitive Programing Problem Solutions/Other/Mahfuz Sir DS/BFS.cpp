#include <stdio.h>
#define MAXSZ 100
#define Q_SIZE 1000
int q[Q_SIZE], frnt = -1, rear = -1;
int mat[MAXSZ][MAXSZ], color[MAXSZ];
void enqueue(int item)
{
    q[++rear] = item;
}
int dequeue()
{
    return q[++frnt];
}
bool isEmpty()
{
    if(frnt == rear)
        return true;
    return false;
}
void bfs(int v, int e, int s)
{
    int current, i;
    enqueue(s);
    color[s] = 1;
    while(!isEmpty())
    {
        current = dequeue();
        for(i=0;i<v;i++)
        {
            if(mat[current][i] == 1 && color[i] == 0)
            {
                enqueue(i);
                color[i] = 1;
            }
        }
        printf("%d ", current);
        color[current] = 2;
    }
}
int main()
{
    int i, j, v, e, a, b, start;
    printf("Total Vertices: ");
    scanf("%d", &v);
    printf("Total Edges: ");
    scanf("%d", &e);
    for(i=0;i<v;i++)
        color[i] = 0;
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            mat[i][j] = 0;
    for(i=0;i<e;i++)
    {
        scanf("%d %d", &a, &b);
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    scanf("%d", &start);
    bfs(v, e, start);
    return 0;
}
