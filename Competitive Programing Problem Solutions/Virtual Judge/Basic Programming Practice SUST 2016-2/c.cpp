#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    if(n==1||n==2){

        cout<<"1"<<endl;
        cout<<"1"<<endl;
    }
    else if(n==3){
        cout<<"2"<<endl;
        cout<<"1"<<" "<<"3"<<endl;
    }
    else if(n%2==0){
        cout<<n<<endl;
        for(int i=n-1;i>=1;i=i-2){
            cout<<i<<" ";
        }
        for(int i=n;i>=4;i=i-2){
            cout<<i<<" ";;
        }
        cout<<"2"<<endl;
        cout<<endl;
    }
    else{
        cout<<n<<endl;
        cout<<"1";
        for(int i=3;i<=n;i=i+2){
            cout<<" "<<i;
        }
        for(int i=2;i<n;i=i+2){
            cout<<" "<<i;
        }
        cout<<endl;
    }
    return 0;
}
/*

*/
