#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,n,m;
    int **ara;
    printf("Enter the total number of class: ");
    scanf("%d",&m);
    int num[m];
    ara == (int**)malloc(sizeof(int*)*n);
    if(ara==NULL){
            perror("Memory allocation failed\n");
            return EXIT_FAILURE;
    }

    for(i=0;i<m;i++){
        printf("Enter the number of students of class %d: ",i+1);
        scanf("%d",&n);
        num[i] = n;
        ara[i] == (int*)malloc(sizeof(int)*n);

        if(ara[i]==NULL){
            perror("Memory allocation failed\n");
            return EXIT_FAILURE;
        }

        for(j=0;j<n;j++){
            printf("Enter marks for student %d: ",j+1);
            scanf("%d", &ara[i][j]);
        }
    }
    printf("Output\n");

    for(i=0;i<m;i++){
        printf("Class %d: ",i+1);
        for(j=0;j<num[i];j++){
            printf("%4d",ara[i][j]);
        }
        printf("\n");
    }
    return 0;
}

