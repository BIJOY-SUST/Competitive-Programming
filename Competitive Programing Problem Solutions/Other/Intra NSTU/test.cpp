#include<bits/stdc++.h>
#define mx 1000001
using namespace std;
bool mark[mx];
vector<int>prime;
void sieve(){
    memset(mark,true,sizeof(mark));
    mark[0]=mark[1]=false;
    for(int i=4;i<=mx;i+=2) mark[i]=false;
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(mark[i]){
            for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
}
long long int Eular_Phi(long long int n){
    if(n==1) return 0;
    long long int ans=n;
    int sqrtn=sqrt(n);
    for(int i=0;i<prime.size()&&prime[i]<=sqrtn;i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
            }
            sqrtn=sqrt(n);
            ans/=prime[i];
            ans*=prime[i]-1;
        }
    }
    if(n!=1&&n>1){
        ans/=n;
        ans*=n-1;
    }
    return ans;
}
int main(){
//    freopen("111.txt","r",stdin);
//    freopen("112.txt","w",stdout);
    sieve();
    long long int n;
    while(scanf("%lld",&n)&&n!=0){
        printf("%lld\n",Eular_Phi(n));
//    for(int i=0;i<=25;i++){
//        cout<<i<<" "<<Eular_Phi(i)<<endl;
//    }
    }
    return 0;
}
