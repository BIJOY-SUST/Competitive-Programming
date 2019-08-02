#include<stdio.h>
int main()

{
     int i, lenght = 0;
     char str[100];
     gets(str);
     for(i=0; str[i]!='\0'; i++)
     {
        lenght++;
     }
     printf("%d\n", lenght);
     for(i=lenght; i>=0; i--)
     {
        printf("%c",str[i]);
     }
     return 0;
}
