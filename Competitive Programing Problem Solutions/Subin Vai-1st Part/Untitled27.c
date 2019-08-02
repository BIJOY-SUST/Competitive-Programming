#include<stdio.h>
int f_max(int ara[], int n)
{
    int i;
    int max = ara[0];
    for (i = 1; i <n; i++)
    {
        if (ara[i] > max)
        {
            max = ara[i];
        }
    }
    return max;
}
int main()
{
    int n = 11, max;
    int ara[] = {-100, 0, 53, 22, 83, 23, 89, -132, 201, 3, 85};
    max = f_max(ara, n);
    printf("The MAX number is %d.\n", max);
    return 0;
}
