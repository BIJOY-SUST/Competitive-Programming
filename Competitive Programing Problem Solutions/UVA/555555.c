#include<stdio.h>
int main() {
    int i, rows,raw,k, space;
    scanf("%d",&rows);
    for(i=1; i<=(rows+1)/2; ++i)
    {
        if(i==1){
            for(k=1; k<=rows; k++){
                printf("* ");
            }
        }
        else{
        for(raw=i; raw<=(rows+1)/2; raw++) {
            printf("* ");
        }
        for(space=1; space<=i; space++) {
            printf(" ");
        }
        for(raw=i; raw<=(rows+1)/2; raw++) {
            printf("* ");
        }
        }
        printf("\n");

    }
    return 0;
}
