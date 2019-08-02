#include<stdio.h>
#include<stdlib.h>
int comparefunc(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
 int main(){
    int *item,n,i,key;
    printf("Enter number of element: ");
    scanf("%d",&n);
    int ara[n];
    printf("Before sorting\n");
    for(i=0;i<n;i++){
        scanf("%d",&ara[i]);
    }
    qsort(ara, n, sizeof(int), comparefunc);
    while(1){
        printf("Enter the value of the key(0 to exit): ");
        scanf("%d",&key);
        if(key==0){
            break;
        }
        item = (int*)bsearch(&key, ara, n, sizeof(int), comparefunc);
        if(item!=NULL){
            printf("Item found: %d\n",*item);
        }
        else{
            printf("Item not found in array\n");
        }
    }
    return 0;
 }
