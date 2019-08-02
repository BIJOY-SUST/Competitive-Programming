/*
ID: bsbijoy1
LANG: C++
TASK: ride
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    int s = 1, ss=1;
    string g,c;
    cin>>g;
    cin>>c;
    for(int i=0; i<g.length(); i++)
    {
        s = s*(g[i]-'@');
    }
    for(int i=0; i<c.length(); i++)
    {
        ss = ss*(c[i]-'@');
    }
    if(s%47 == ss%47)
    {
        cout<<"GO"<<endl;
    }
    else
    {
        cout<<"STAY"<<endl;
    }

    return 0;


}
