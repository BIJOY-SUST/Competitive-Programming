#include<stdio.h>
#include<math.h>
int prime(int n)
{
    int j;
    if(n<2 || n%2 == 0 && n>2)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }
    for(j=3; j<sqrt(n); j=j+2)
    {
        if(n%j == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int i, n, m,c=0;
    int a, b;
    printf("Enter the starting point:");
    scanf("%d", &a);
    printf("Enter the ending point:");
    scanf("%d", &b);
    for(n=a; n<b; n++)
        {
             m = prime(n);
            if(m == 1)
            {
                c++;
            }
            else
            {
                continue;
            }
        }
        if(n == b) {
            m = prime(n);
            if(m == 1)
            {
                c++;
            }
        }
        printf("%d", c);
    return 0;
}
