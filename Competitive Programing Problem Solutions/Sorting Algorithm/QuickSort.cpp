#include<bits/stdc++.h>
#define mx 10001
using namespace std;
int arr[mx];
void Swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int Partition(int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<=pivot){
            i++;
            Swap(&arr[i],&arr[j]);
        }
    }
    Swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quick_sort(int low,int high){
    if(low<high){
        int p=Partition(low,high);
        quick_sort(low,p-1);
        quick_sort(p+1,high);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quick_sort(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
