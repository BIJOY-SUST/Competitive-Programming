#include<bits/stdc++.h>
using namespace std;
const int mx 10000001;
bool arr[mx];
vector<long long int>prime;
void sieve(){
    prime.push_back(2);
    arr[0]=arr[1]=1;
    for(long long int i=4;i<=mx;i+=2) arr[i]=1;
    for(long long int i=3;i<sqrt(mx);i+=2){
        for(long long int j=i*i;j<=mx;j=j+2*i){
            arr[j]=1;
        }
    }
    for(long long int i=3;i<=mx;i+=2){
        if(arr[i]==0){
            prime.push_back(i);
        }
    }
}
