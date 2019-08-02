#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main(){
    int i,t;
    double h,s;
    double d,r1,r2,r3;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf %lf",&h,&s);
        r1 = atan (((double)s/(double)h)) * 180.0 / PI;
        r2 = atan (((double)h/(double)s)) * 180.0 / PI;
//        printf("%lf %lf\n",r1,r2);
        r3=r1-r2;
        d=tan ( r3 * PI / 180.0 )*s;

        printf("%lf\n",d);
    }
    return 0;
}
