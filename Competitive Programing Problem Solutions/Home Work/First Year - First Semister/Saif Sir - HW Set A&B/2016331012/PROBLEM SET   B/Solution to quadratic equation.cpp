#include<stdio.h>
#include<math.h>

int main(){
    double a,b,c;
    double det,x1,x2;

    while(scanf("%lf %lf %lf",&a,&b,&c) && (b*b - 4*a*c) >=0){
        det = b*b - 4*a*c;
        if(det == 0){
            x1 = x2 = -b/(2*a);
            printf("%lf     %lf\n",x1 ,x2);
        }
        else if(det > 0){
            x1 = ( -b + sqrt(det)) / (2* a);
            x2 = ( -b - sqrt(det)) / (2* a);
            printf("%lf     %lf\n",x1 ,x2);
        }
    }
    return 0;
}
