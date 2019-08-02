#include<stdio.h>
int main(){
    FILE *input1_file, *input2_file, *input3_file, *output_file;
    input1_file = fopen("math.txt", "r");
    input2_file = fopen("Bengali.txt", "r");
    input3_file = fopen("English.txt","r");
    output_file = fopen("Avarage.txt", "w");
    int i,j,a,b,c;
    float Avarage;
    for(i=1;i<=10;i++){
        fscanf(input1_file,"%d %d",&j ,&a);
        fscanf(input2_file,"%d %d",&j ,&b);
        fscanf(input3_file,"%d %d",&j ,&c);
        Avarage = (float)(a+b+c)/3;
        fprintf(output_file,"%d %f\n", i,Avarage);
    }
    fclose(input1_file);
    fclose(input2_file);
    fclose(input3_file);
    fclose(output_file);

}
