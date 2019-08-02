#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1||n==2){

        cout<<"1"<<endl;
        cout<<"1"<<endl;
    }
    else if(n==3){
        cout<<"2"<<endl;
        cout<<"1"<<" "<<"3"<<endl;
    }
    else if(n%2==0){
        cout<<n<<endl;
        for(int i=n-1;i>=1;i=i-2){
            cout<<i<<" ";
        }
        for(int i=n;i>=4;i=i-2){
            cout<<i<<" ";;
        }
        cout<<"2"<<endl;
        cout<<endl;
    }
    else{
        cout<<n<<endl;
        cout<<"1";
        for(int i=3;i<=n;i=i+2){
            cout<<" "<<i;
        }
        for(int i=2;i<n;i=i+2){
            cout<<" "<<i;
        }
        cout<<endl;
    }
    return 0;
}
