#include<stdio.h>
#include<stdlib.h>

int add(int a, int b)
{
    int s = a + b;
    return s;
}

int main()
{
    int *array, length, i, sum = 0;

    printf("Enter Number of intergers: ");
    scanf("%d", &length);
    array = (int*)malloc(sizeof(int)*length);

    for(i=0;i<length;i++)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%d", &array[i]);
        sum = add(sum, array[i]);
    }

    printf("The average is %lf\n", (double)sum/length);

    return 0;
}
