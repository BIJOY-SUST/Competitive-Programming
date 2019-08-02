#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y,a,b;
    cin>>n>>x>>y>>a>>b;
    double f = sqrt(pow((b-y),2.0)+pow((a-x),2.0));
    int k = (int)(ceil(f/(2*n)));
    cout<<k<<endl;
    return 0;

}
