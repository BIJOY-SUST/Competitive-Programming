#include<stdio.h>
int main()
{
    double marks[4][10] = {{80,70,92,78,58,83,85,66,99,81},{75,67,55,100,91,84,79,61,90,97},{98,67,75,89,81,83,80,90,88,77},{0,0,0,0,0,0,0,0,0,0}};
    int col;
    for(col=0; col<10; col++)
    {
        marks[3][col] = marks[0][col] /4.0 + marks[1][col]/4.0 + marks[2][col]/2.0;
        printf("ROLL No: %d    Total Marks: %.3lf\n", col+1, marks[3][col]);
    }
    return 0;
}
