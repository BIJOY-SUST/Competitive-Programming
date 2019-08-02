#include<bits/stdc++.h>
#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
int a[mx];
int aq[mx];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>aq[i];
    }
    int j,k;
    for(int i=0;i<q;i++){
        bool fa=true;
        bool fb=true;
        int f,b;
        for(j=0;j<n;j++){
            if(aq[i]<a[j]&&fa==true){
                f=j;
                fa=false;
            }
        }
        for(k=n-1;k>=0;k--){
            if(aq[i]>a[k]&&fb==true){
                b=k;
                fb=false;
            }
        }
        if(fa==false&&fb==false){
            cout<<a[b]<<" "<<a[f]<<endl;
        }
        else if(fa==false&&fb==true){
            cout<<"X"<<" "<<a[f]<<endl;
        }
        else if(fa==true&&fb==false){
            cout<<a[b]<<" "<<"X"<<endl;
        }
    }
    return 0;
}
/**
Input:

Output:

**/
