#include <stdio.h>
#include <string.h>

int main()
{
    char s[25], t[25], r[25];
    int i, j, k, tc;
    scanf("%d", &tc);
    getchar();
    for(i = 1; i <= tc; i++)
    {
        gets(s);
        gets(t);

        if(!strcmp(s, t))
        {
            printf("Case %d: Yes\n", i);
        }
        else
        {
            k = 0;

            for(j = 0; s[j]; j++)
            {
                if(isalpha(s[j]))
                    r[k++] = s[j];
            }
            r[k] = '\0';

            if(strcmp(t,r) == 0)
                printf("Case %d: Output Format Error\n", i);
            else
                printf("Case %d: Wrong Answer\n", i);
        }
    }

    return 0;
}
