#include<bits/stdc++.h>
#define max 1000000
using namespace std;
long long int A[max];
int main(){
    long long int n,c,x,y,d;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    cin>>c;
    while(c--){
        cin>>x>>y;
        if((A[x]%2==1)||(A[x+1]==0&&x<y)){
            cout<<"Odd"<<endl;
        }
        else{
            cout<<"Even"<<endl;
        }
    }
    return 0;
}
