#include<stdio.h>

struct s{
    char ch;
    int n;
    char str[16];
};
union u{
    char ch;
    int n;
    char str[16];
};

int main(){

    printf("Structure variable took %d bytes.\n",sizeof(struct s));
    printf("Union variable took %d bytes.\n",sizeof(union u));

    return 0;
}
