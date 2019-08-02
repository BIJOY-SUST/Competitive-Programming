#include<stdio.h>

int main(){

    FILE *output_file;
    output_file = fopen("my_file.txt", "w");


    fprintf(output_file,"This is my pen.");
    fclose(output_file);
    return 0;

}

