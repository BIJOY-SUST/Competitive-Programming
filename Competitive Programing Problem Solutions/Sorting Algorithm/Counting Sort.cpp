#include<bits/stdc++.h>
#define mx 10001
using namespace std;
int arr[mx];
void counting_sort(int n){
    int output[n];
    int count[mx+1];
    memset(count,0,sizeof(count));
    for(int i=0;i<n;i++){
        ++count[arr[i]];
    }
    for(int i=1;i<=mx;i++){
        count[i]+=count[i-1];
    }
    for(int i=0;i<n;i++){
        output[count[arr[i]]-1]=arr[i];
        --count[arr[i]];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    counting_sort(n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
