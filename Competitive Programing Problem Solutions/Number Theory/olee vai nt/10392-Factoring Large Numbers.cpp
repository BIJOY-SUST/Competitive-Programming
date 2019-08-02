#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
bool arr[mx];
vector<int>prime;
vector<long long int>factor;
void sieve(){
    prime.push_back(2);
    arr[0]=arr[1]=1;
    for(int i=4;i<=mx;i+=2) arr[i]=1;
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(arr[i]==0){
            for(int j=i*i;j<=mx;j+=2*i) arr[j]=1;
        }
    }
    for(int i=3;i<=mx;i+=2) if(arr[i]==0){
            prime.push_back(i);
    }
}
void prime_factor(long long int n){
    int sqrtn=sqrt(n);
    for(int i=0;i<prime.size()&&prime[i]<=sqrtn;i++){
//        if(arr[n]==0) break;
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                factor.push_back(prime[i]);
            }
            sqrtn=sqrt(n);
        }
    }
    if(n!=1) factor.push_back(n);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    long long int n;
    while(cin>>n){
        if(n<0) break;
        //cout<<'\n';
        prime_factor(n);
        for(int i=0;i<factor.size();i++){
            cout<<"    "<<factor[i]<<'\n';
        }
        factor.clear();
        cout<<'\n';
//    for(int i=0;i<1000;i++){
//        cout<<prime[i]<<endl;
//    }
    }
    return 0;
}

