#include <stdio.h>
#include <math.h>
#define pi  2*acos(0.0)
int main(){
    int T,count = 1;
    double r,radius, area;
    scanf("%d", &T);
    while(T--){
        scanf("%lf", &radius);
        r = 2*radius;
        area = r*r - pi*radius*radius;
        printf("Case %d: %.2lf\n", count, area);
        count++;
    }
    return 0;
}
