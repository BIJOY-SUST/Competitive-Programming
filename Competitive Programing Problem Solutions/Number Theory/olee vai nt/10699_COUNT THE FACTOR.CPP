#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
bool mark[mx];
vector<int>prime;
vector<int>factor;
void sieve(){
    memset(mark,true,sizeof(mark));
    mark[0]=mark[1]=false;
    for(int i=4;i<=mx;i+=2) mark[i]=false;
    for(int i=3;i*i<=mx;i+=2){
        if(mark[i]){
            for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
}
void prime_factor(int n){
    int sqrtn=sqrt(n);
    for(int i=0;i<prime.size()&&prime[i]<=sqrtn;i++){
//      if(arr[n]==0) break;
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
//    freopen("indev.txt","r",stdin);
//    freopen("outdev.txt","w",stdout);
//    sieve();
    sieve();
    int n;
    while(cin>>n){
        if(n==0) break;
        prime_factor(n);
        factor.erase(unique(factor.begin(),factor.end()),factor.end());
        cout<<n<<" : "<<factor.size()<<'\n';
        factor.clear();
    }
//    for(int i=0;i<factor.size();i++){
//        cout<<factor[i]<<'\n';
//    }
//    for(int i=0;i<1000;i++){
//        cout<<prime[i]<<endl;
//    }
    return 0;
}
