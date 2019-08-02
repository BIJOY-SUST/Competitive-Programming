#include<bits/stdc++.h>
using namespace std;
#define mx 100000001
long long int arr[mx];
int main(){

    arr[0]=arr[1]=1;
    int k=1;
    for(int i=2;i<=mx;i++){
        ++k;
        arr[k]=arr[i-1]+arr[i-2];
    }
    for(int i=0;i<=15;i++)
            cout<<arr[i]<<" ";
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
    }
    return 0;
}
