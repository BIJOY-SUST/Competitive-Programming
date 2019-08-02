#include<stdio.h>
int main()
{
    int i,ceil,floor;
    double n;
    while(scanf("%lf", &n)){

    floor = (int)n;
    if(floor == n){
        ceil = floor;
    }
    else{
        ceil = floor+1;
    }
    printf("%d  %d\n", floor, ceil);
    }
    return 0;
}
