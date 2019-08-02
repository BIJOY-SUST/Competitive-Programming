#include<stdio.h>
#define MAX_SZ 100

int mat[MAX_SZ][MAX_SZ], color[MAX_SZ], STK[MAX_SZ], top = -1;
void push(int item)
{
    STK[++top] = item;
}
int pop()
{
    return STK[top--];
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
    printf("Total Vertices:");
    scanf("%d", &v);
    printf("Total Edges:");
    scanf("%d", &e);
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            mat[i][j] = 0;
    for(i=0;i<v;i++)
        color[i] = 0;
    for(i=0;i<e;i++)
    {
        scanf("%d %d", &a, &b);
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    printf("Starting node: ");
    scanf("%d", &start);
    dfs(v, e, start);
    return 0;
}
