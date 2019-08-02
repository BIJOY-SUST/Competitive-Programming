#include<bits/stdc++.h>
using namespace std;

template<class T>T absolute(T x){
    if(x<0){
        return -x;
    }
    else{
        return x;
    }
}

int main(){
    int n;
    while(cin>>n){
    cout<<absolute(n)<<endl;
    }
    return 0;
}
