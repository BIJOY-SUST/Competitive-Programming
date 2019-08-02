#include<stdio.h>
int string_lenght(char a[], char b[])
{
    int i;
    for(i=0; a[i]!='\0' && b[i]!='\0'; i++)
    {
        if(a[i] < b[i])
        {
            return -1;
        }
        if(a[i] > b[i])
        {
            return 1;
        }
         if(a[i] == b[i])
        {
            return 0;
        }

    }
    if(string_lenght(a) == string_lenght(b))
    {
        return 0;
    }
    if(string_lenght(a) < string_lenght(b))
    {
        return -1;
    }
    if(string_lenght(a) > string_lenght(b))
    {
        return 1;
    }
}
int main()
{
    char a[1000], b[1000];
    int i, string_compare;
    printf("Please enter string a:");
    scanf("[^\n]", a);
    printf("Please enter string b:");
    scanf("[^\n]", b);
    string_compare = string_lenght(a,b);
    printf("The winner is:%d\n", string_compare);
    return 0;

}


