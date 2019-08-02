#include<stdio.h>

int main(){

    FILE *intput_file;
    intput_file = fopen("aaa.txt", "r");
    char input[80];
    fgets(input, 80, intput_file);
    puts(input);
    fclose(intput_file);
    return 0;
}
