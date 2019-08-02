#include<stdio.h>
int main()
{
    int i, j,R,C;
    scanf("%d %d",&R,&C);
    char ara3[R][C];
    char ara4[R][C];

    for(i=0;i<R;i++)
    {
       scanf(" %[^\n]",ara3[i]);
    }
    for(j=0; j<C; j++)
    {
        for(i=0; i<R; i++)
        {
            ara4[j][R-1-i] = ara3[i][j];
        }
    }
    for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
        {
            printf("%c", ara4[i][j]);
        }
        printf("\n");
    }
    return 0;
}
