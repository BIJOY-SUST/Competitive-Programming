#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long X=0,Y=0,n,bx,by,xi,yi;
    cin>>n>>bx;
    for(int i=0;i<n;i++){
        cin>>xi;
        X = X*bx+xi;
    }
    cin>>n>>by;
    for(int i=0;i<n;i++){
        cin>>yi;
        Y = Y*by+yi;
    }
    if(X>Y){
        cout<<">"<<endl;
    }
    else if(X<Y){
        cout<<"<"<<endl;
    }
    else{
        cout<<"="<<endl;
    }

    return 0;
}
