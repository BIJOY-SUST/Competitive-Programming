#include<stdio.h>
int main()
{
    int n, i, Value;
    for(n = 1; n<=20; n = n+1)
    {
       for(i = 1; i<=10; i = i+1)
       {
           Value = n*i;
           printf("%d X %d = %d\n", n, i, Value);
       }

      }
    return 0;
}
