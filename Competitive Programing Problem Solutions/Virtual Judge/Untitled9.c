#include <stdio.h>
#include <math.h>
#define PI acos(0.0)*2
int main()
{
    int x,y,z;
    double a,b,c,d,f,g,h;
    double e;
    scanf("%d", &x);
    for(y=1; y<=x; y++){
        scanf("%lf%lf", &a, &b);
        c=(PI/b);
        d=sin(c);
        e=(a*d)/(1+d);
        z=(int) e;
        h=(e*1.0)/z;
        if(h!=1)
           printf("Case %d: %.10lf\n",y, e);
        else
           printf("Case %d: %.0lf\n",y, e);
    }
    return 0;
}
