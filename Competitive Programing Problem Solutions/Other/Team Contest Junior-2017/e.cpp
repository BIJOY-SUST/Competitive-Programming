#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //sort(arr,arr+n);
    for(int i=n-2;i>=0;i--){
        while(arr[i+1]>arr[i]+1){
            arr[i+1]=arr[i+1]-1;
        }
    }
//    for(int i=0;i<n;i++){
//        printf("%d ",arr[i]);
//    }
//    printf("\n");

//    int n=max_element(arr,arr+n);
    //sort(arr,arr+n);
    printf("%d",arr[n-1]+1);
    return 0;
}
