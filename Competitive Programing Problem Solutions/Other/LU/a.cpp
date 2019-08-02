#include<bits/stdc++.h>
#define mx 1001
using namespace std;
int arr[mx];
//int twin[mx];
void sieve(){
    int i,j;
    arr[0]=arr[1]=1;
    for(i=4;i<=mx;i=i+2) arr[i]=1;
    for(i=3;i<=sqrt(mx);i=i+2){
        for(j=i*i;j<=mx;j=j+2*i){
            arr[j]=1;
        }
    }
    //for(i=2;i<=mx;i++){
        //if(arr[i]==0){
           // twin[k]=i;
           // k++;
       // }
    //}
}
int main(){
    sieve();
    int n;
    cin>>n;
    if(arr[n]==0){
        cout<<"NO PUNISHMENT\n";
    }
    else{
        while(n--){
            cout<<"I DID NOT DO THE ASSIGNMENT.\n";
        }
    }
    return 0;
}
