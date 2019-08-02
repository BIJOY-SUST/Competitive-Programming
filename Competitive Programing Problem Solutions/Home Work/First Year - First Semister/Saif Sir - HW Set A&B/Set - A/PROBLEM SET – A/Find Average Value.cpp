#include <stdio.h>

int main()
{
    int n, i, count = 1;
    float num[100], sum = 0.0, average;

    while(scanf("%d", &n)){
        sum = 0.0;
        for(i = 0; i < n; i++)
        {
            scanf("%f", &num[i]);
            sum += num[i];
        }

        average = sum / n;
        printf("Case %d : %f\n", count, average);
        count++;
    }

    return 0;
}
