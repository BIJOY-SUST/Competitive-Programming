#include<stdio.h>
int str_lenght(char str[])
{
    int i, lenght=0;
    for(i=0; str[i]!='\0'; i++)
     {
         lenght++;
     }
     return lenght;
}
int main()
{
    int lenght;
    char str[100];
    gets(str);;
    lenght=str_lenght(str);
    printf("The number of lenght is %d\n", lenght);
    return 0;
}
