#include<stdio.h>
int main()
{
    int n,i, max;
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
    printf("%d\n", max);
    }
    return 0;
}
