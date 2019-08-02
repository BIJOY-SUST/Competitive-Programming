#include<stdio.h>
int main()
{
    int ft_marks, st_marks, fi_marks;
    double total_marks;
    scanf("%d %d %d", &ft_marks, &st_marks, &fi_marks);
    total_marks = ft_marks/4 + st_marks/4 + fi_marks/2;
    printf("%lf\n", total_marks);
    return 0;
}
