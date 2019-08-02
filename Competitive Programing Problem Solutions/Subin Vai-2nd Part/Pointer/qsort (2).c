#include<stdio.h>
#include<stdlib.h>
int comparefunc(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
int main(){
    int i,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int ara[n];
    printf("Before sorting\n");
    for(i=0;i<n;i++){
        scanf("%d",&ara[i]);
    }

    qsort(ara, n, sizeof(int), comparefunc);

    printf("After sorting\n");
    for(i=0;i<n;i++){
        printf("%d  ",ara[i]);
    }

    return 0;
}
