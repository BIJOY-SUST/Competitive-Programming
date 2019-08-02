#include<stdio.h>
#include<stdlib.h>
int main(){

    FILE *fq;
    fq = fopen("in.txt", "r");

    if(fq==NULL){
        perror("Can't open file");
        return EXIT_FAILURE;
    }

    int ch;
    ch = fgetc(fq);
    printf("%c\n",(char)ch);
    ch = fgetc(fq);
    printf("%c\n",(char)ch);
    ch = fgetc(fq);
    printf("%c\n",(char)ch);

    fseek(fq, 5, SEEK_CUR);
    ch = fgetc(fq);
    printf("%c\n",(char)ch);

    fclose(fq);
    return 0;
}
