#include<stdio.h>
int main()
{
    int n,k,p,a,s,i;
    while(scanf("%d",&a)==1)
    {
        for(i=1;i<=a;i++)
        {
            scanf("%d%d%d",&n,&k,&p);
            s=k+p;
            while(s>n)
            {
                s=s-n;
            }
            printf("Case %d: %dn",i,s);
        }
    }
    return 0;
}
