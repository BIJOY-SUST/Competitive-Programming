#include<stdio.h>
int mat[100][100], indeg[100], visited[100], n, e, st[100], fn[100], k;
void DFS(int cur)
{
    int i;
    //printf("%d ", cur);
    for(i=0;i<n;i++)
    {
        if(mat[cur][i] && visited[i] == 0)
        {
            visited[i] = 1;
            st[i] = ++k;
            DFS(i);
            fn[i] = ++k;
        }
    }
}
void TopologicalSort()
{
    int i, j, t, ind[100];
    for(i=0;i<n;i++)
    {
        ind[i] = i;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(fn[i]<fn[j])
            {
                t = fn[i];
                fn[i] = fn[j];
                fn[j] = t;

                t = st[i];
                st[i] = st[j];
                st[j] = t;

                t = ind[i];
                ind[i] = ind[j];
                ind[j] = t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ", ind[i]);
    }
}
int main()
{
    int i, j, a, b;
    scanf("%d %d", &n, &e);
    for(i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            mat[i][j] = 0;
    for(i=0;i<e;i++)
    {
        scanf("%d %d", &a, &b);
        mat[a][b] = 1;
    }
    k = 0;
    st[1] = ++k;
    DFS(1);
    fn[1] = ++k;
    TopologicalSort();
    return 0;
}

/*
0 1 2
3 4 5
B E D F A C
1 4 3 5 0 2

6 7
1 0
1 2
1 4
4 3
4 5
3 0
5 2

after DFS
1 0 2 4 3 5
B A C E D F
After sort
1 4 5 3 2 0
B E F D C A
*/
