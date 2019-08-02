#include<stdio.h>
int main()
{
    int i, j=0, lenght = 0;
    char str[100], str_new[100];
    gets(str);
    for(i=0; str[i] != '\0'; i++)
    {
        lenght++;
    }
    printf("Lenght is %d\n", lenght);
    for(i=lenght-1; i>=0; i--)
    {
         str_new[j] = str[i];
         j=j+1;
    }
    str_new[j]='\0';
    printf("%s\n", str_new);

    return 0;
}

