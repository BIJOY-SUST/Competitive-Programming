#include<bits/stdc++.h>
using namespace std;
int main()
{
    int b,n;
    cin>>n;
    if(n<=2){
        cout<<-1<<endl;
    }
    else{
       for(b=n;b>0;b--){
        cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}
