#include<stdio.h>
int Q[1000], frnt = -1, rear = -1, mat[100][100], indeg[100], visited[100], n, e;
void Enqueue(int item)
{
    Q[++rear] = item;
}
int Dequeue()
{
    return Q[++frnt];
}
bool isEmpty()
{
    if(frnt == rear)
        return true;
    return false;
}
void TopologicalSort()
{
    int i, cnt, cur;
    for(i=0;i<n;i++)
    {
        if(indeg[i] == 0)
            Enqueue(i);
    }
    cnt = 0;
    while(!isEmpty() && cnt < n)
    {
        cur = Dequeue();
        visited[cur] = 1;
        for(i=0;i<n;i++)
        {
            if(mat[cur][i] == 1 && visited[i] == 0)
            {
                indeg[i]--;
                if(indeg[i] == 0)
                    Enqueue(i);
            }
        }
        printf("%d ", cur);
        cnt++;
    }
}
int main()
{
    int i, j, a, b;
    scanf("%d %d", &n, &e);
    for(i=0;i<n;i++)
    {
        visited[i] = 0;
        indeg[i] = 0;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            mat[i][j] = 0;
    for(i=0;i<e;i++)
    {
        scanf("%d %d", &a, &b);
        mat[a][b] = 1;
        indeg[b]++;
    }
    TopologicalSort();
    return 0;
}


