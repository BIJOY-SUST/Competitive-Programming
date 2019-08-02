#include<stdio.h>
int main()

{
     int i, lenght = 0;
     char str[10000];
     gets(str);
     for(i=0; str[i]!='\0'; i++)
     {
        lenght++;
     }
     for(i=lenght-1; i>=0; i--)
     {
        printf("%c",str[i]);
     }

     return 0;
}
