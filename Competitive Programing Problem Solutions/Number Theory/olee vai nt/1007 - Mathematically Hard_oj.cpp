#include<bits/stdc++.h>
#define mx 5000001
using namespace std;
bool mark[mx];
vector<int>prime;
unsigned long long phi[mx];
void Eular_Phi_sieve(){
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
    for(int i=0;i<=mx;i++){
        phi[i]=i;
    }
    for(int i=0;i<prime.size();i++){
        int p=prime[i];
        for(int j=p;j<=mx;j+=p){
            phi[j]=(phi[j]*(p-1)/p);
        }
    }
}
int main(){
    Eular_Phi_sieve();
    for(int i=1;i<=mx;i++){
        phi[i]=phi[i]*phi[i];
        phi[i]=phi[i]+phi[i-1];
    }
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        unsigned long long a,b;
        scanf("%llu %llu",&a,&b);
        printf("Case %d: %llu\n",i,phi[b]-phi[a-1]);
    }
    return 0;
}
