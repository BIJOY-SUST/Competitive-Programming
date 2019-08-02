#include <stdio.h>

int main()
{
    int n, i;
    int num[100], sum = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    printf("%d\n", sum);
    return 0;
}

