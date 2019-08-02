#include<stdio.h>
#include<stdlib.h>
int main(){
    int *marks;
    int i,n;
    printf("Please enter the number of student: \n");
    scanf("%d",&n);

    marks = (int*)malloc(sizeof(int)*n);

    if(marks==0){
        perror("Memory allocation failed for marks\n");
        return EXIT_FAILURE;
    }
    printf("Enter the number of student: \n");
    for(i=0;i<n;i++){
        scanf("%d",&marks[i]);
    }

    printf("Now here you can see the value:\n");
    for(i=0;i<n;i++){
        printf("%d\n",marks[i]);
    }

    free(marks);

    return 0;
}
