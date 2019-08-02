#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
bool arr[mx];
vector<int>prime;
void sieve(){
    prime.push_back(2);
    arr[0]=arr[9]=1;
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
int SOD(int n){
    int sqrtn=sqrt(n);
    int ans=1;
    for(int i=0;i<prime.size()&&prime[i]<=sqrtn;i++){
        int c=1,tempsum=1;
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                c*=prime[i];
                tempsum+=c;
            }
            sqrtn=sqrt(n);
            ans*=tempsum;
//            cout<<n<<" "<<sqrtn<<" "<<c<<'
        }
    }
    if(n!=1) ans*=(n+1);
    return ans;
}
int main(){
    sieve();
    int n;
    cin>>n;
    cout<<SOD(n)<<'\n';
    return 0;
}
