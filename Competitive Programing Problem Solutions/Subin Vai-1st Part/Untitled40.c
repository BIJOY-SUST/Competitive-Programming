#include<stdio.h>
int main()
{
    int i, n, yes = 0;
    printf("Enter a number:");
    scanf("%d", &n);
    if(n<2)
    {
        printf("%d is not a prime number.\n", n);
    }
    if(n==2)
    {
        printf("%d is a prime number", n);
    }
    if(n>2)
    {
        for(i=2; i<n; i++)//Best equation : for(i=2; i<=n/2; i++)
        {
            if(n%i == 0)
            {
                printf("%d is not a prime number\n", n);
                yes = 1;
                break;
            }
        }
    }
    if(n>2 && yes==0)
    {
        printf("%d is a prime number", n);
    }
    return 0;
}
