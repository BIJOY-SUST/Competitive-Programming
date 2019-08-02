#include<stdio.h>
int main()
{
    int ara[5][5] = {{6,4,7,8,9},{3,7,1,9,9},{8,6,4,2,7},{2,4,2,5,9},{4,1,6,7,3}};
    int i,j,sum[5]={0,0,0,0,0}, col;
    for(col=0; col<5; col++)
    {
        for (i = 0; i<5; i++)
        {
              sum[col]= sum[col] + ara[i][col];
        }
        printf("Sum of column %d : %d\n", col+1, sum[col]);
   }
    return 0;
}

