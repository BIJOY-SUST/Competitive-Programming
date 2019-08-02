#include<stdio.h>

struct s{
    char ch;
    int n;
    char str[16];
}ss;
union u{
    char ch;
    int n;
    char str[16];
}uu;

int main(){
    int struct_size,union_size;

    struct_size = sizeof(ss);
    union_size = sizeof(uu);

    printf("Structure variable took %d bytes.\n",struct_size);
    printf("Union variable took %d bytes.\n",union_size);

    return 0;
}
