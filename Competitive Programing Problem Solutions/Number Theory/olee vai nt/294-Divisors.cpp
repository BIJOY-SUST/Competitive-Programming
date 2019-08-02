#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
bool arr[mx];
vector<int>prime;
void sieve(){
    prime.push_back(2);
    arr[0]=arr[1]=1;
    for(int i=4;i<=mx;i+=2) arr[i]=1;
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(arr[i]==0){
            for(int j=i*i;j<=mx;j+=2*i) arr[j]=1;
        }
    }
    for(int i=3;i<=mx;i+=2) if(arr[i]==0){
        prime.push_back(i);
    }
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
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    freopen("indev.txt","r",stdin);
//    freopen("outdev.txt","w",stdout);
    sieve();
    int t;
    cin>>t;
    while(t--){
        long long P,D=0;
        long long  L,H;
        cin>>L>>H;
        for(int i=L;i<=H;i++){
            int nod=NOD(i);
            if(nod>D){
                P=i;
                D=nod;
            }
        }
        cout<<"Between "<<L<<" and "<<H<<", "<<P<<" has a maximum of "<<D<<" divisors."<<'\n';
    }
    return 0;
}
