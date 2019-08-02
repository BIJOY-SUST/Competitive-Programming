#include<stdio.h>

union u{
    char ch;
    int x;
    int y;
}uv;

int main(){
    uv.ch = 'A';
    printf("uv.ch = %c\n",uv.ch);
    printf("uv.x = %d\n",uv.x);

    uv.x = 17;
    printf("uv.x = %d\n",uv.x);
    printf("uv.ch = %c\n",uv.ch);

    uv.y = 15;
    printf("uv.y = %d\n",uv.y);
    printf("uv.x = %d\n",uv.x);
    printf("uv.ch = %c\n",uv.ch);



    return 0;
}
