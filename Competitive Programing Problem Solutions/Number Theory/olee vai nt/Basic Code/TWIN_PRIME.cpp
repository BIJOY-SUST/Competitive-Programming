#include<bits/stdc++.h>
#define mx 20000000
using namespace std;
bool mark[mx];
vector<int>prime;
vector<pair<int,int> >t_prime;
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
void twin_prime(){
    for(int i=0;i<prime.size()-1;i++){
        if(prime[i+1]-prime[i]==2){
            t_prime.push_back(make_pair(prime[i],prime[i+1]));
        }
    }
}
int main(){
    sieve();
    twin_prime();
    int n;
    while(cin>>n){
        cout<<"("<<t_prime[n-1].first<<", "<<t_prime[n-1].second<<")"<<'\n';
    }
    return 0;
}


