#include<stdio.h>
int main()
{
    char n;
    scanf("%c", &n);
    if(n>='a' && n<='z')
    {
        printf("%c is a lower case\n", n);
    }
    else if(n>='A' && n<='Z')
    {
        printf("%c is upper case\n", n);
    }
    return 0;
}
