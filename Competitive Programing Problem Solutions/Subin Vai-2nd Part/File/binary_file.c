#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *input_file, *output_file;
    input_file = fopen("cse1.jpg","rb");
    output_file = fopen("cse2.jpg", "wb");

    int ch;
    if(input_file==NULL){
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    while(1){
        ch = fgetc(input_file);
        if(ch == EOF){
            break;
        }
        fputc(ch, output_file);
    }
    fclose(input_file);
    fclose(output_file);

}
