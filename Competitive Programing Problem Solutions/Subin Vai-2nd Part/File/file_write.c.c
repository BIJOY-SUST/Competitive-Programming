#include<stdio.h>

int main(){

    FILE *output_file;
    output_file = fopen("my_file.txt", "w");

    char input[100000];
    gets(input);
    fputs(input, output_file);
    fclose(output_file);
    return 0;

}
