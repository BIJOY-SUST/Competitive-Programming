#include<stdio.h>
int main()
{
    char country[] = {'B', 'a', 'n', 'g', 'l', 'a', 'd', 'e', 's', 'h','\0'};
    printf("%s\n", country);
    int i;
    for(i=0; i<=10; i++)
    {
        if(country[i]>=65 && country[i]<=90)
        {
            country[i] = country[i] + 32;
        }
    }
    printf("%s\n", country);
}

