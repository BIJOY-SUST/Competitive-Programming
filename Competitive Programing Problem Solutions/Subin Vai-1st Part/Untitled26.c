#include<stdio.h>
double add(double sum1, double sum2)
{
    double y;
    y = sum1 + sum2;
    return y;
}
int main()
{
    double a, b, c;
    scanf("%lf %lf", &a, &b);
    c = add(a, b);
    printf("The sum of a and b is %.3lf.\n", c);
    return 0;
}
