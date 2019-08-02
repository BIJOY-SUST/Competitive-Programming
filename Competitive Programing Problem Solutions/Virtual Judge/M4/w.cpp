#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,f,g;
    cin>>a>>b;
    f= min(a,b);
    g = max(a,b);
    cout<<f<<" ";
    if((g-f)%2==0){
        cout<<(g-f)/2<<endl;
    }
    else{
        cout<<(g-f-1)/2<<endl;
    }
    return 0;
}
