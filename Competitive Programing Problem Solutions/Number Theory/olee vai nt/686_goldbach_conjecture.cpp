#include<bits/stdc++.h>
#define mx 1<<15
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
    prime.clear();
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
}
int main(){
    sieve();
    int n;
    while(scanf("%d",&n)&&n!=0){
        int ans=0;
        for(int j=0;prime[j]<=n/2;j++){
            int k=n-prime[j];
            if(mark[k]){
                ans++;
//                cout<<prime[j]<<" "<<k<<endl;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

