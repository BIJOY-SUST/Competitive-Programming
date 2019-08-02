#include<stdio.h>
int main()
{
    int n,i=1;
    while(scanf("%d",&n)==1 && n>1)
    {
        printf("Case %d: %d\n",i,n/2);
        i++;
    }
    return 0;
}
