#include<stdio.h>
#include<math.h>
int prime(int n)
{
    int i;
    if(n<2 || n%2 == 0 && n>2)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    for(i=3; i<=sqrt(n); i=i+2)//Best equation : for(i=2; i<=n/2; i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int i, n;
    printf("Enter a number:");
    scanf("%d", &n);
    if(prime(n) == 0)
    {
        printf("%d is not a prime number\n", n);
    }
    if(prime(n) == 1)
    {
        printf("%d is a prime number\n", n);
    }
    return 0;
}

