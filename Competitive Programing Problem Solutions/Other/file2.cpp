#include<stdio.h>
int main(){
    FILE *output_file;
    output_file = fopen("math.txt","w");
    for(int i=1;i<=100;i++){
        fprintf(output_file,"%d\n",i);
    }
    fclose(output_file);
    return 0;
}
