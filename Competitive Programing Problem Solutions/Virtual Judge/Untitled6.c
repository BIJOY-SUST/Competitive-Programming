#include <stdio.h>
int main()
{
    int T,i,M,j,x,y,g,h,x1,x2,y1,y2;
    scanf("%d", &T);
    for(i=1; i<=T; i++)
    {
        printf("Case %d:\n",i);
        scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
        scanf("%d", &M);
        for(j=1; j<=M; j++)
        {
            scanf("%d %d", &x, &y);
            if(((x>=x1) &&(x<=x2)) && ((y>=y1)&&(y<=y2)))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
