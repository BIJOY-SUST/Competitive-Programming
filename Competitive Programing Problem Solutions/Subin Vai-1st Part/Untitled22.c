#include<stdio.h>
int main()
{
    int i;
    char x;
    char s_l[25] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char c_l[25] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    printf("Incert a Character:");
    scanf("%c", &x);
    if(x>='a' && x<='z')
    {
        for (i=0; i<26; i++)
        {
           if(s_l[i]==x)
           {
                s_l[i]=c_l[i];
                printf("The change character is %c\n", s_l[i]);
                break;
           }
        }
    }
    else if(x>='A' && x<='Z')
    {
        for (i=0; i<26; i++)
        {
           if(c_l[i]==x)
           {
               c_l[i]=s_l[i];
                printf("The change character is %c\n", c_l[i]);
                break;
           }
        }
    }
    else
    {
        printf("Please enter a character\n");
    }
    return 0;
}
