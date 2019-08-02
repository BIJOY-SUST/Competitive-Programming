#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *input_file;
    input_file = fopen("cse1.jpg","rb");

    if(input_file == NULL){
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    fseek(input_file,0,SEEK_END);
    printf("File Size: %ld bytes\n",ftell(input_file));
    printf("File Size: %ld kolobytes\n",ftell(input_file)/1024);
    fclose(input_file);
    return 0;
}
