#include<stdio.h>
int main()
{
    int a,b,x,gcd;
    scanf("%d %d", &a, &b);
    if(a>b)
    {
        x=a;
    }
    else
    {
        x=b;
    }
    for(; x>=1; x++)
    {
        if(x%a == 0 && x%b == 0)
        {
            gcd = x;
            printf("GCD is %d\n", gcd);
            break;
        }
    }

    return 0;
}

