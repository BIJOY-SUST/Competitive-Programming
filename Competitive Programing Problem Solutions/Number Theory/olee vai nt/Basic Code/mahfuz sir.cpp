#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    printf("Enter the size of the Array:\n");
    int n,cmd,i=0,x,y;
    scanf("%d",&n);
    int arr[n];
    printf("Press 1 for insert an element\n");
    printf("Press 2 for delete an element\n");
    printf("Press 3 for update an element\n");
    printf("Press 4 for sort the Array\n");
    printf("Press 5 for print the Array\n");

    while(scanf("%d",&cmd)==1&&cmd!=0){
        if(cmd==1){
            if(i==n) printf("Overflow\n");
            else{
                printf("Enter an element:\n");
                scanf("%d",&arr[i++]);
                printf("Inserted\n");
            }
        }
        else if(cmd==2){
            if(i==0) printf("Ops! Array is empty\n");
            else{
                bool flag=true;
                printf("Enter the element you want to delete:\n");
                scanf("%d",&x);
                for(int j=0;j<i;j++){
                    if(arr[j]==x){
                        flag=false;
                        for(int k=j;k<i-1;k++){
                            swap(arr[k],arr[k+1]);
                        }
                        i--;
                    }
                }
                if(flag) printf("Element does't exist\n");
                else printf("Removed\n");
            }
        }
        else if(cmd==3){
            if(i==0) printf("Ops! Array is empty\n");
            else{
                 bool flag=true;
                 printf("Enter the old element and the new element you want to update\n");
                 scanf("%d %d",&x,&y);
                 for(int j=0;j<i;j++){
                    if(arr[j]==x){
                        arr[j]=y;
                        flag=false;
                    }
                 }
                 if(flag) printf("Element does't exist\n");
                 else printf("Updated\n");
            }
        }
        else if(cmd==4){
            if(i==0) printf("Ops! Array is empty\n");
            else{
                sort(arr,arr+i);
                printf("Sorted\n");
            }
        }
        else if(cmd==5){
            if(i==0) printf("Ops! Array is empty\n");
            else{
                for(int j=0;j<i;j++){
                    printf("%d ",arr[j]);
                }
                printf("\n");
            }
        }
        else printf("Unknown Command\n");
    }
    return 0;
}
