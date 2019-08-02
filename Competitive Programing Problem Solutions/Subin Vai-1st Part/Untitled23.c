#include<stdio.h>
int main()
{
    char x, i, j;
    printf("Incert a Character:");
    scanf("%c", &x);
    if(x>='a' && x<='z' || x>='A' && x<='Z')
    {
        for (i='a', j='A'; i<='z', j<='Z'; i++, j++)
        {
            if (i==x)
                {
                    i=j;
                    printf("The change character is %c\n", i);
                    break;
                }
            if (j==x)
                {
                    j=i;
                    printf("The change character is %c\n", j);
                    break;
                }
        }
    }

    return 0;
}
