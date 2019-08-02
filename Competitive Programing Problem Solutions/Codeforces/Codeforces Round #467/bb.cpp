#include<bits/stdc++.h>
#define ll             long long int
#define mx             1000000001
using namespace std;
bool mark[mx];
vector<int>prime;
void sieve(){
    memset(mark,true,sizeof(mark));
    mark[0]=mark[1]=false;
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(mark[i]) for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
}
int main(){
    sieve();
    ll p,y;
    scanf("%lld%lld",&p,&y);
    if(y%2==0) y--;
    bool ff=false;
    ll ans;
    for(ll i=y;i>2;i-=2){
        bool f=false;
        for(int j=0;prime[j]<=p;j++){
            if(i%prime[j]==0){
                f=true;
                break;
            }
        }
        if(f) continue;
        else{
            ff=true;
            ans=i;
            break;
        }
    }
    if(ff){
        printf("%lld\n",ans);
    }
    else{
        printf("-1\n");
    }
    return 0;
}

