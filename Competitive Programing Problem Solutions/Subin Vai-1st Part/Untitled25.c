#include<stdio.h>
int square(int x)
{
    int y;
    y = x*x;
    return y;
}
int main()
{
    int a, value;
    scanf("%d", &a);
    value = square(a);
    printf("The square %d is %d.\n", a, value);
    return 0;
}
