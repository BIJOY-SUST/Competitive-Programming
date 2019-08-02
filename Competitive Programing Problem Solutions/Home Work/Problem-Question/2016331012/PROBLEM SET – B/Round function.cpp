#include<stdio.h>
int round(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}
int main()
{
    int i;
    double n;
    while(scanf("%lf", &n)){
    i = round(n);
    printf("%d\n",i);
    }
    return 0;
}



