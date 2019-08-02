#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<< #x" " << x << endl;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    ll t, n;
    cin >> t;
    while(t--)
    {
        int c=0;
        cin >> n;
        int x=log2(n);
//        cout<<x<<endl;
        bool f=false;
        for(int i=0; i<=x; i++)
        {
            int j=(n&(1<<i));
            if(j!=0) break;
            else c++;
//            cout<<j<<endl;
//            if(j!=0)
//                f=true;
//            if(!f)
//            {
//                if(j==0)
//                    c++;
//            }
        }
        cout<< c+1<<endl;
    }

    return 0;
}
