#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i]);
        }
        int c=0;
        for(int h=0;h<n-1;h++){
            for(int k=h+1;k<n;k++){
                if(arr[h]>arr[k]){
                    c++;
                    int temp=arr[h];
                    arr[h]=arr[k];
                    arr[k]=temp;
                }
            }
        }
        printf("Case %d: %d\n",i,c);
    }
    return 0;
}
