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
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
}
int main(){
    sieve();
    int x,y;
    while(cin>>x>>y){
        if(x==0&&y==0) break;
        bool flag=true;
        for(int i=0;prime[i+2]<=y;i++){
            if(prime[i]>=x){
                if(flag==false){
                    if(abs(prime[i-1]-prime[i])==abs(prime[i]-prime[i+1])){
                    cout<<" "<<prime[i+1];//cout<<"gese"<<'\n';
                    }
                    else{
                        cout<<'\n';
                        flag=true;
                    }
                }
                else if(abs(prime[i]-prime[i+1])==abs(prime[i+1]-prime[i+2])){
                    cout<<prime[i]<<" "<<prime[i+1]<<" "<<prime[i+2];
                    flag=false;
                    i++;
                }
            }
        }
    }
    return 0;
}


