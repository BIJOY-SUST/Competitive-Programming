#include<bits/stdc++.h>
#define mx 5000001
using namespace std;
bool mark[mx];
vector<int>prime;
unsigned long long phi[mx];
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
int Eular_Phi(int n){
    int ans=n;
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
    sieve();
    for(int i=0;i<=mx;i++){
        phi[i]=Eular_Phi(i);
    }
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
//    int t;
//    scanf("%d",&t);
//    for(int i=0;i<=25;i++){
//        cout<<Eular_Phi(i)<<endl;
//        long long int a,b;
//        scanf("%lld %lld",&a,&b);
//        printf("Case %d: %lld\n",Eular_Phi(b)-Eular_Phi(a));
//    }
    return 0;
}


