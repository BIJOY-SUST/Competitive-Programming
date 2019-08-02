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
    int i, j=0, lenght;
    char str[30];
    char str_new[50];
    gets(str);
    //lenght=str_lenght(str);
    //printf("%d\n", lenght);
    for(i=str_lenght(str)-1; i>=0; i--)
    {
         str_new[j] = str[i];
         j=j+1;
    }
    str_new[j]='\0';
    printf("%s\n", str_new);

    return 0;
}
