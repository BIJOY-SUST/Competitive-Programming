#include <stdio.h>
#include <string.h>

int main()
{
   char string[100];
   int c,T,i, count[26]={0};
   printf("Enter: ");
   scanf("%d", &T);
    for(i=0; i<T; i++) {

   printf("Enter a string: );
   scanf(" %[^\n]", string);
   for(i=0; i<strlen(string); i++)
    {

      if (string[i] >= 'a' && string[i] <= 'z')
         count[string[i]-'a']++;
   }
    for (i = 0; i < 26; i++)
   {

      if (count[i] != 0)
         printf("%c occurs %d times.\n",i+'a',count[i]);
   }
   }
    return 0;
}
