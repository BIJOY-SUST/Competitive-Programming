#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int N;
    cin>>N;
    while(N>1){
        if(N%1000==144){
            N=N/1000;
        }
        else if(N%100==14){
            N=N/100;;
        }
        else if(N%10==1){
            N=N/10;
        }
        else{
            break;
        }
    }
    if(N>1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
    return 0;
}
