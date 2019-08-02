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
        d=(s*s-h*h)/(2*h);
        printf("%.10f\n",d);
    }
    return 0;
}

