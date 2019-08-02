#include<bits/stdc++.h>
#define mx 10000005
using namespace std;
int k=0;
int arr[3*mx];
void sieve(){
    long long i,j;
    memset(arr,0,sizeof(arr));
    arr[0]=arr[1]=1;
    for(i=4;i<=mx;i=i+2) arr[i]=1;
    for(i=3;i<=sqrt(mx);i=i+2){
        for(j=i*i;j<=mx;j=j+2*i){
            arr[j]=1;
        }
    }
    for(i=1;i<=mx;i++){
        if(arr[i]==0){
            arr[i]=k++;
        }
        else{
            arr[i]=k;
        }
    }
}
int main(){
    sieve();
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        printf("%d\n",arr[n]);
    }
    return 0;
}


