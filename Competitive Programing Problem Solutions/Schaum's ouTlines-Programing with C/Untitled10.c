#include<stdio.h>
#include<ctype.h>
int main() {
    char x;
    scanf("%c", &x);
    x = toupper(x);
    if(x == 'A' || 'E' || 'I' || 'O' || 'U') {
        printf("vowel");
    }
    else {
        printf("con");
    }
    return 0;
}
