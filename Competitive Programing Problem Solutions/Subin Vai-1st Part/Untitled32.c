 #include<stdio.h>
 int main()
 {
     int i, lenght=0;
     char str[30];
     gets(str);
     for(i=0; str[i]!='\0'; i++)
     {
         lenght++;
     }
     printf("Lenght of %s is %d\n", str, lenght);
    return 0;
 }
