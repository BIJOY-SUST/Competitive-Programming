#include<stdio.h>
int main(){
    FILE *output_file;
    output_file = fopen("English.txt", "w");
    int i;
    char input[1000];
    for(i=1;i<=10;i++){
        gets(input);
        fputs(input,output_file);
        fprintf(output_file,"\n");
    }

    fclose(output_file);
    return 0;
}
