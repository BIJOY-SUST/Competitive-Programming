#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define llu            unsigned long long int
#define mx             100010
//#define mod            100000007
//const long long inf =  1e15;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//-----------------------------------------------------
//-----------------------Bitmask-----------------------
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//-----------------------------------------------------
using namespace std;
vector<ll>v;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ll k;//scanf("%I64d",&k);
        cin>>k;
        v.push_back(k);
    }
    sort(v.rbegin(),v.rend());
    ll ans1=0,ans2=0;
    int c=0,k;
    for(int i=0;i<n-1;i++){
        if(v[i]==v[i+1]&&c==0){
            ans1=v[i];
            c++;
            i++;
        }
        else if(v[i]==v[i+1]&&c==1){
            ans2=v[i];
            break;
        }
    }
    cout<<ans1*ans2<<'\n';
    return 0;
}
