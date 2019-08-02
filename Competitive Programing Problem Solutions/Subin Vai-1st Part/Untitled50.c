#include<stdio.h>
int main()
{
    int ara[5][5] = {{6,4,7,8,9},{3,7,1,9,9},{8,6,4,2,7},{2,4,2,5,9},{4,1,6,7,3}};
    int i,j,sum[5]={0,0,0,0,0}, col;
    for(i=0; i<5; i++)
    {
        for (col = 0; col<5; col++)
        {
              sum[i]= sum[i] + ara[i][col];
        }
        printf("Sum of row %d : %d\n", i+1, sum[i]);
   }
    return 0;
}
