#include<stdio.h>
int main(){
    FILE *i_file, *o_file;
    i_file = fopen("int2.txt","r");
    o_file = fopen("out.txt","w");

    int a,b,sum;
    char input[1000];

    fgets(input,1000,i_file);

    fputs(input, o_file);

    fclose(i_file);
    fclose(o_file);

    return 0;
}
