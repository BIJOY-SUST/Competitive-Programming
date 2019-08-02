#include<stdio.h>
int main()
{
    int n,i,min,max,diff;
    while(scanf("%d", &n) == 1){
    int ara[n];
    for(i=0; i<n; i++){
        scanf("%d", &ara[i]);
    }
    max = ara[0];
    for (i = 1; i <n; i++)
    {
        if (ara[i] > max)
        {
            max = ara[i];
        }
    }
    min = ara[0];
    for (i = 1; i <n; i++)
    {
        if (ara[i] < min)
        {
            min = ara[i];
        }
    }
    diff = max - min;
    printf("%d\n", diff);
    }
    return 0;
}
