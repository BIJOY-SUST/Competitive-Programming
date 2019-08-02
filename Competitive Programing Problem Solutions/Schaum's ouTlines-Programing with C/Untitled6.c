#include<stdio.h>
#include<string.h>
#define NL '\n'
int main() {
    char letter[1000];
    int i, j;
    for(i=0; (letter[i] = getchar()) != NL; i++) {
        j=i;
    }
    for(i=0; i<=j; i++) {
        putchar(toupper(letter[i]));
    }
    return 0;
}


