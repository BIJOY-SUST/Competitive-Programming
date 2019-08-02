#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        long long x,d,i;
        cin>>x;
        d = sqrt(x);
        for(i=2;i*i<=d;i++){
            if(d%i==0){
                break;
            }
        }
        if(d*d == x&&i*i>d&&x>1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
