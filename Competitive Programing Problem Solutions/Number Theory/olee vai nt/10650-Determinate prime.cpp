#include<bits/stdc++.h>
#define mx 32000
using namespace std;
bool arr[mx];
vector<int>prime;
void sieve(){
    arr[0]=arr[1]=1;
    for(int i=4;i<=mx;i+=2) arr[i]=1;
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(arr[i]==0){
            for(int j=i*i;j<=mx;j+=2*i) arr[j]=1;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(arr[i]==0) prime.push_back(i);
}
int main(){
    sieve();
    int x,y;
    while(cin>>x>>y){
    if(x==0&&y==0) break;
    if(x>y){
        swap(x,y);
    }
    bool flag=true;
    for(int i=0;prime[i]<=y;i++){
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
//            if(abs(prime[i+2]-prime[i+3]!=abs(prime[i+1]-prime[i+2]))){
//                cout<<'\n';
//                flag=true;
//            }
            i++;
        }
        }
        //cout<<i+1<<" "<<prime[i]<<endl;
    }
    }
    return 0;
}


