#include<stdio.h>
int main()
{
    int ft_marks[4] = {40, 55, 66, 77, 88}, st_marks[4] = {40, 33, 66, 77, 88}, fi_marks[4] = {40, 89, 66, 77, 88};
    int i;
    double total_marks[4];
    for (i=0; i<4; i++)
    {
        total_marks[i] = ft_marks[i]/4 + st_marks[i]/4 + fi_marks[i]/2;
    }
    for (i=1; i<=4; i++)
    {
        printf("Roll No: %d\t Total Marks: %lf\n", i, total_marks[i-1]);
    }
    return 0;
}
