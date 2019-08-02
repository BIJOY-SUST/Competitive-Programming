#include<stdio.h>

int main(){

    FILE *output_file;
    output_file = fopen("append.txt", "w");


    fprintf(output_file,"This is my pen.");
    fprintf(output_file,"This is my ball.");
    fclose(output_file);
    output_file = fopen("append.txt", "a");

    fprintf(output_file,"This is my book.");
    return 0;

}
