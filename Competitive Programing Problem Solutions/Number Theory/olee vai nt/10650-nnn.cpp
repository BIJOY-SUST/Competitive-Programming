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
//    freopen("indev.txt","r",stdin);
//    freopen("outdev.txt","w",stdout);
    sieve();
    int x,y;
    while(cin>>x>>y){
        if(x==0&&y==0) break;
        if(x>y) swap(x,y);
        bool flag=true;
        for(int i=0;prime[i+2]<=y;i++){
            if(prime[i]>=x){
                if(abs(prime[i]-prime[i+1])==abs(prime[i+1]-prime[i+2])){
                    int s=i;
                    int f=i+2;
                    int d=prime[i+1]-prime[i];
                    while(i+3<=prime.size()&&(prime[i+3]-prime[i+2]==d)){
                        f++;
                        i++;
                    }
                    if(prime[f]<=y){
                        if(s==0||prime[s]-prime[s-1]!=d){
                            cout<<prime[s];
                            for(int j=s+1;j<=f;j++){
                                cout<<" "<<prime[j];
                            }
                            cout<<'\n';
                        }
                    }

                }
            }
        }
    }
    return 0;
}



