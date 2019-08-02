#include<stdio.h>

int main(){

    int i;
    FILE *output_file;
    output_file = fopen("my_nofile.txt", "w");

    for(i=65;i<=90;i++){
        fprintf(output_file,"%c\n",i);
    }

    fclose(output_file);
    return 0;

}
