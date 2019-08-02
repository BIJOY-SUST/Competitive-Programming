#include<stdio.h>
int main()
{
    int n,i, min;
    while(scanf("%d", &n) == 1){
    int ara[n];
    for(i=0; i<n; i++){
        scanf("%d", &ara[i]);
    }
    min = ara[0];
    for (i = 1; i <n; i++)
    {
        if (ara[i] < min)
        {
            min = ara[i];
        }
    }
    printf("%d\n", min);
    }
    return 0;
}
