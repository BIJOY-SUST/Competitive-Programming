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
void prime_factor(long long n){
    for(int i=0;i<prime.size()&&prime[i]<=n;i++){
        long long x=n;
        int c=0;
        if(x/prime[i]){
            while(x/prime[i]){
                c+=n/prime[i];
                x=x/prime[i];
            }
            factor[prime[i]]=c;
//            printf("%d^%d\n",prime[i],c);
        }
    }
}
void fact_factor(long long n){
//    for(int i=2;i<=n;i++)
    prime_factor(n);
    printf("%lld! =",n);
    for(int i=0;i<factor.size();i++){
        if(i==0) printf(" %d^%d",prime[i],factor[prime[i]]);
        else printf(" x %d^%d",prime[i],factor[prime[i]]);
    }
    printf("\n");
}
int main(){
    sieve();
    long long n;
    scanf("%d",&n);
    fact_factor(n);
    return 0;
}


