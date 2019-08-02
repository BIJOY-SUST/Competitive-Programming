#include<stdio.h>
int main()
{
    char str1[100], str2[100], str3[100];
    int i, j;
    gets(str1);
    gets(str2);
    for(i=0,j=0; i<6;i++, j++)
    {
        str3[j]=str1[i];
    }
    for(i=0; i<4;i++, j++)
    {
        str3[j]=str2[i];
    }
    str3[j]='\0';
    printf("%s\n", str3);
}
