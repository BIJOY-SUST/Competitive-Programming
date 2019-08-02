#include<stdio.h>

int main()
{
    int t, n, speed, max, i, j;
    while(scanf("%d",&t)==1)
    {
        for(i=1;i<=t;i++)
        {
            max=0;
            scanf("%d",&n);
            for(j=1;j<=n;j++)
            {
                scanf("%d",&speed);
                if(speed>max)
                    max=speed;
            }
            printf("Case %d: %d\n",i,max);
        }
    }
    return 0;
}
