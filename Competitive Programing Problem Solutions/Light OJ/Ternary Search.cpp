#include<bits/stdc++.h>
//#define mx             100010
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
vector<int>a;
int ternary_search(int l,int r,int key){
    while(l<=r){
        int mid1=l+(r-l)/3;
        int mid2=r-(r-l)/3;
        if(key==a[mid1]) return mid1;
        else if(key==a[mid2]) return mid2;
        else if(key<a[mid1]) r=mid1-1;
        else if(key>a[mid2]) l=mid2+1;
        else{
            l=mid1+1;
            r=mid2-1;
        }
    }
    return -1;
}
//int ternary_search(int l,int r,int key){
//    while(r-l>=(1e-6)){
//        if(r-l<(1e-6)) return (l+r)/2;
//        int mid1=l+(r-l)/3;
//        int mid2=r-(r-l)/3;
//        if(func(mid1)<func(mid2)) l=mid1;
//        else r=mid2;
//    }
//}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int h; scanf("%d",&h);
        a.push_back(h);
    }
    sort(a.begin(),a.end());
    int key;
    scanf("%d",&key);
    int x;
    if((x=ternary_search(0,n-1,key))==-1){
        printf("Key is not found\n");
    }
    else{
        printf("Key is found at %d\n",x);
    }
    return 0;
}
/**
Input:
5
1 3 8 13 18
13
Output:

**/
