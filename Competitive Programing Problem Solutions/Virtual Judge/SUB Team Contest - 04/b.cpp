#include<bits/stdc++.h>
using namespace std;
const double pi = acos(0.0)*2;
int main()
{
    //cout<<pi<<endl;
    int n;
    double g,x,y,d[6],t[6];
    cin>>n>>g;
    for(int i=0;i<n;i++){
        cin>>d[i]>>t[i];
    }
    vector<double>ans;
    double u=0,v,a;

    for(int i=n-1;i>=0;i--){
        a = g*cos(t[i]*pi/180.0);
        v = u*u + 2*a*d[i];
        v = sqrt(v);
        //cout<<v<<endl;
        ans.push_back(v);
        u = v;
    }
    for(int i=n-1;i>=0;i--) printf("%0.6lf\n",ans[i]);
    return 0;
}

