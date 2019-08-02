#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main(){
    int t;
    double h,s;
    double d,r1,r2,r3;
    scanf("%d",&t);
    while(t--){
        scanf("%lf %lf",&h,&s);
        r1=atan(s/h)*180.0/PI;
        r2=atan(h/s)*180.0/PI;
//        printf("%lf %lf\n",r1,r2);
        r3=r1-r2;
        d=tan(r3*PI/180.0)*s;
        printf("%.10lf\n",d);
    }
    return 0;
}
