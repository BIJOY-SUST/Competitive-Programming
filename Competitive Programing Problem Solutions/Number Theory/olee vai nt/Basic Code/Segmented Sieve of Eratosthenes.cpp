#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
bool arr1[mx];
vector<int>prime;
void sieve(){
    prime.push_back(2);
    arr1[0]=arr1[1]=1;
    for(int i=4;i<=mx;i+=2) arr1[i]=1;
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(arr1[i]==0){
            for(int j=i*i;j<=mx;j+=2*i) arr1[j]=1;
        }
    }
    for(int i=3;i<=mx;i+=2) if(arr1[i]==0){
            prime.push_back(i);
    }
}
int Segmented_Sieve(int a,int b){
    int arr2[b-a+1];
    if(a==1) a++;
    int sqrtb=sqrt(b);
    memset(arr2,0,sizeof(arr2));
    for(int i=0;i<prime.size()&&prime[i]<=sqrtb;i++){
        int p=prime[i];
        int j=p*p;
        if(j<a) j=((a+p-1)/p)*p;
        for(;j<=b;j+=p) arr2[j-a]=1;
    }
    int ans=0;
    for(int i=a;i<=b;i++){
        if(arr2[i-a]==0) ans++;
    }
    return ans;
}
int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    sieve();
    int a,b;
    cin>>a>>b;
    cout<<Segmented_Sieve(a,b)<<'\n';
//    for(int i=0;i<1000;i++){
//        cout<<prime[i]<<endl;
//    }
    return 0;
}
