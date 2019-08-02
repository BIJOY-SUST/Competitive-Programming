#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100], str2[100], str3[100];
    int i,T,T2,m,j,n1,n2,n3;
    scanf("%d", &T);
    while(T--) {
    scanf(" %[^\n]",str1);
    scanf(" %[^\n]",str2);
    n1=strlen(str1);
    n2=strlen(str2);
    for(i=0,j=0; i<n1;i++, j++)
    {
        str3[j]=str1[i];
    }
    str3[j]=' ';
    j++;
    for(i=0; i<n2;i++, j++)
    {
        str3[j]=str2[i];
    }
    str3[j]='\0';
    printf("%s\n", str3);
    n3=strlen(str3);
    for(i=0; i<n3-1; i++) {
        for(j=0; j<n3-i-1; j++){
            if(str3[j]>str3[j+1]){
                m = str3[j];
                str3[j] = str3[j+1];
                str3[j+1] = m;
            }
        }
    }
    printf("%s", str3);
    }
    return 0;
}
