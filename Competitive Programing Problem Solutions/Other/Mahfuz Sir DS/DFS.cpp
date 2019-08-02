#include <stdio.h>
#define MAXSZ 100
#define S_SIZE 100
int stk[S_SIZE], top = -1;
int mat[MAXSZ][MAXSZ], color[MAXSZ];
void push(int item)
{
    stk[++top] = item;
}
int pop()
{
    return stk[top--];
}
bool isEmpty()
{
    if(top == -1)
        return true;
    return false;
}
void dfs(int v, int e, int s)
{
    int current, i;
    push(s);
    color[s] = 1;
    while(!isEmpty())
    {
        current = pop();
        for(i=0;i<v;i++)
        {
            if(mat[current][i] == 1 && color[i] == 0)
            {
                push(i);
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
    dfs(v, e, start);
    return 0;
}
