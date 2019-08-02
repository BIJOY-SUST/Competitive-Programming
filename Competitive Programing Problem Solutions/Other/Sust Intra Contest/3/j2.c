#include<bits/stdc++.h>
using namespace std;
#define mx 1005
bool arr[mx];
int k=1;
int twin[mx];

void sieve(){
    long long int i,j;
    arr[0]=arr[1]=1;
    for(i=4;i<=mx;i=i+2) arr[i]=1;
    for(i=3;i<=sqrt(mx);i=i+2){
        for(j=i*i;j<=mx;j=j+2*i){
            arr[j]=1;
        }
    }
    for(i=2;i<=mx;i++){
        if(arr[i]==0){
            twin[k]=i;
            k++;
        }
    }
}

int main(){
    long long int t,h,m,r,g,c,s;
    cin>>t;
    sieve();
    for(h=1;h<=t;h++){
        for(int i=0;i<k;i++){

        }
    }
    return 0;
}


