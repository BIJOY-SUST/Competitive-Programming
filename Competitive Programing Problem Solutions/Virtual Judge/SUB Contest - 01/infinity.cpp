#include<bits/stdc++.h>
//#define mx             100001
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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,time,x,c=0,A=0,B=0,t=0,strike=1;
    cin>>n>>time;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x!=-1) {
            if(strike==1) {A+=x;}
            else if(strike==2) {B +=x;}
            t += x;
            if(x%2==1) strike = 3-strike;
        }
        c++;
        if(x==-1){
//            if(flag) swap(A,B);
            if(strike==1) {cout<<A<<" "<<t<<"\n"; A=0;}//if(!flag)A=0;/*else B=0;*/}
            else if(strike==2) {cout<<B<<" "<<t<<"\n"; B=0;}//if(!flag)B=0;/*else A=0;*/}
//            if(flag) swap(A,B),flag=false;
        }
        if(time==c) swap(A,B),c=0/*,flag=true*/;
        //printf("a=%d, b=%d\n",A,B);
    }
    cout<<t<<endl;
    return 0;
}
/*
Input:

Output:

*/


