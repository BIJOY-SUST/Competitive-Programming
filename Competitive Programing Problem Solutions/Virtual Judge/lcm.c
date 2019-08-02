#include<stdio.h>
int main()
{
    long long int n,a,b,c,lcm;

    while(scanf("%lld",&n)){
    a=n;
    b=n-1;
    c=n-2;

    for(; ; n++)
    {
        if(n%a == 0 && n%b == 0 && n%c==0)
        {
            lcm = n;
            printf("%lld\n", lcm);
            break;

        }
    }
    }
    return 0;
}
