#include <stdio.h>
int main()
{
    int a,b,c,d,e,f;
    scanf("%d", &c);
    for(d=1; d<=c; d++)
    {
        scanf("%d%d", &a, &b);
        if(a<=b)
            e=4*b+19;
        else{
            e=(a-b)*4 +a*4+19;
        }
        printf("Case %d: %d\n", d,e);
    }
    return 0;
}

