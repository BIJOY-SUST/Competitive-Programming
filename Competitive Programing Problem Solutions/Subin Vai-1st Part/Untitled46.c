#include<stdio.h>
int main()
{
    double ara[4][2];
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            scanf("%lf", &ara[i][j]);
        }
    }
    for(j=0; j<2; j++)
    {
        ara[3][j] = ara[0][j] /4.0 +ara[1][j]/4.0 + ara[2][j]/2.0;
        printf("ROLL No: %d    Total Marks: %.3lf\n", j+1, ara[3][j]);
    }
    return 0;
}

