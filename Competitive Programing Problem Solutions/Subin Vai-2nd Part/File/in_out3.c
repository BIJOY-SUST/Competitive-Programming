#include<stdio.h>
int main(){
    FILE *i_file, *o_file;
    i_file = fopen("input.txt","r");
    o_file = fopen("o_file.txt","w");

    int a,b,sum;
    char input[1000];

    fgets(input,1000,i_file);
    //puts(input);
    printf("Input: %s\n", input);

    sscanf(input,"%d %d",&a,&b);
    sum = a+b;
    printf("%d %d %d\n", a, b, sum);
    fprintf(o_file, "%d\n",sum);

    fclose(i_file);
    fclose(o_file);

    return 0;
}
