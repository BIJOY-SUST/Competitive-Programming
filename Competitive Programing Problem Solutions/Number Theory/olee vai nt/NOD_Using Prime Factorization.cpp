#include<bits/stdc++.h>
#define mx 10000001
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
int NOD(int n){
    int sqrtn=sqrt(n);
    int ans=1;
    for(int i=0;i<prime.size()&&prime[i]<=sqrtn;i++){
        int c=0;
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                c++;
            }
            sqrtn=sqrt(n);
//            cout<<n<<" "<<sqrtn<<" "<<c<<'\n';
            c++;
            ans*=c;
        }
    }
    if(n!=1) ans*=2;
    return ans;
}
int main(){
    sieve();
    int n;
    cin>>n;
    cout<<NOD(n)<<'\n';
    return 0;
}
