#include<bits/stdc++.h>
#define mx 1000001
using namespace std;
bool mark[mx];
vector<int>prime;
//vector<int>factor;
map<int,int>factor;
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
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                factor[prime[i]]++;
            }
            sqrtn=sqrt(n);
        }
    }
    if(n!=1) factor[n]++;
}
void fact_factor(int n){
    for(int i=2;i<=n;i++) prime_factor(i);
    printf("%d! =",n);
    for(int i=0;prime[i]<=n;i++){
        if(i==0) printf(" %d^%d",prime[i],factor[prime[i]]);
        else printf(" x %d^%d",prime[i],factor[prime[i]]);
    }
    printf("\n");
}
int main(){
    sieve();
    int n;
    scanf("%d",&n);
    fact_factor(n);
    return 0;
}
