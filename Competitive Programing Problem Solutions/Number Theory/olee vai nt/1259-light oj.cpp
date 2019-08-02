#include<bits/stdc++.h>
#define mx 10000005
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
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,ans=0;
        cin>>n;
        for(int j=0;prime[j]<=n/2;j++){
            int k=n-prime[j];
            if(mark[k]){
                ans++;
//                cout<<prime[j]<<" "<<k<<endl;
            }
        }
        cout<<"Case "<<i<<": "<<ans<<'\n';
    }
    return 0;
}
