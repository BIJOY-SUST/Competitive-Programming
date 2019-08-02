#include<stdio.h>
int main()
{
    int n, i, Value;
    scanf("%d", &n);
    for(i=1,Value=0; i<=n; i++)
    {
        Value=Value+i;
    }

        printf("%d\n", Value);
    return 0;
}

