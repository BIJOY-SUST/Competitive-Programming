#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
        long long N,m=0,n,i;
        cin>>N;
        for(i=0;i<N;i++)
        {
            cin>>n;
            m+=n;
        }
        if(m==(N*(N+1))/2){
                cout<<"YES"<<endl;
         }
        else{
               cout<<"NO"<<endl;
         }
    return 0;
}
