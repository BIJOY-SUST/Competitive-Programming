#include <stdio.h>

// s source, m middle, d destination
void tower(int n, char a, char b, char c)
{
    if(n>0)
    {
        // first move n-1 disks from source to middle,
        // using destination as middle pillar
        tower(n-1, a, c, b);
        // the only left nth disk can be moved directly from source to destination
        printf("%c -> %c\n", a, c);
        // on first step we've sent n-1 disks to the middle,
        // and now, from the middle pillar, we'll transfer them back to destination
        // using the source as the middle pillar+
        tower(n-1, b, a, c);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    tower(n, 'a', 'b', 'c');
    return 0;
}
