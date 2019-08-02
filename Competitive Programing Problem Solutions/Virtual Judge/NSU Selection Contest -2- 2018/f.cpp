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
vector<pair<int,int> >v,a,b;
int pos[mx];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    scanf("%d",&n);
    int high=0;
    for(int i=1;i<=n;i++){
        int h; scanf("%d",&h);
        v.push_back({h,i});
        pos[i]=h;
        high=max(high,h);
    }
    sort(v.begin(),v.end());
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        if(i&1){
            a.push_back(v[i]);
            sum1+=v[i].first;
        }
        else{
            b.push_back(v[i]);
            sum2+=v[i].first;
        }
    }
    //if(abs(a.size()-b.size())<=1&&abs(sum1-sum2)<=high){
        printf("%d\n",a.size());
        for(int i=0;i<a.size();i++){
            printf("%d ",a[i].second);
        }
        printf("\n");
        printf("%d\n",b.size());
        for(int i=0;i<b.size();i++){
            printf("%d ",b[i].second);
        }
        printf("\n");
    //}
    return 0;
}
/**
Input:

Output:

**/
