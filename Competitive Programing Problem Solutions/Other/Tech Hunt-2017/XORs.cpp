#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cout<< #x <<"= " << x << endl;

int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        ll jor;
        cin >> n;
        ll a;
        cin >> a;
        jor=a;
        for(int i=1;i<n;i++)
        {
            cin >> a;
            jor=jor^a;
        }
        if(n%2==0)
        {
            cout<< jor<<endl;
        }
        else
            cout<< "0"<<endl;
    }
return 0;
}
