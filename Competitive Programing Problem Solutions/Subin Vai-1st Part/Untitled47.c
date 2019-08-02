#include<stdio.h>
int main()
{
    int i,j;
    int ara[10][10];

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            ara[i][j] = (i+1) * (j+1);
        }
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf("%d  X   %d = %d\n", (i+1), (j+1), ara[i][j]);
        }
        printf("\n");
    }
    return 0;
}
