#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,T,len,count=0;
    char str[1000],str_new[1000];
    scanf("%d", &T);
    for(i=0; i<T; i++) {
        scanf(" %[^\n]", str);//Dhaka is the capital of Bangladesh
        len = strlen(str);
        for(i=len-1,j=0; i>=0; i--)
    {
         str_new[j] = str[i];
         j=j+1;
    }
    str_new[j]='\0';
    printf("%s\n", str_new);
    }
    return 0;
}
