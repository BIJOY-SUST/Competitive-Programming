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
bitset<12>a[1010];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(scanf("%d",&n)==1){
        int ans=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            while(x!=0){
                int d=x%10;
                x/=10;
                a[i]|=(1<<d);
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]!=0){
                for(int j=i+1;j<n;j++){
                    if(a[i]==a[j]) a[j]=0;
                }
                ans++;
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<1010;i++) a[i]=0;
    }
    return 0;
}
/*
Input:

Output:

*/
