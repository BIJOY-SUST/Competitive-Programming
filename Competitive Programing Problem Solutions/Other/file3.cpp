#include<stdio.h>
int main(){
    int m;
    FILE *output_file;
    output_file = fopen("math.txt","r");
    for(int i=50;i<=100;i++){
        fscanf(output_file,"%d",&m);
        printf("%d\n",m);
    }
    fclose(output_file);
    return 0;
}

