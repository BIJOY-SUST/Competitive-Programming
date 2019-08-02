#include<stdio.h>
#include<string.h>
#define NL '\n'
int main() {
    char letter[1000];
    int i=0, j;
    while((letter[i] = getchar()) != NL) {
        i++;
        j=i;
    }

    i=0;
    while(i<j) {
        putchar(toupper(letter[i]));
        i++;
    }
    return 0;
}
