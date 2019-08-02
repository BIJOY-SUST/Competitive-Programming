#include<stdio.h>
#define Max(a,b)(a>b? a:b)
int main(){
    int a = 83, b = 323;
    double x = 8.2325145525, y = 3.3214523;

    printf("Maximum value : %d\n",Max(a,b));
    printf("Maximum value : %lf\n",Max(x,y));

    return 0;
}
