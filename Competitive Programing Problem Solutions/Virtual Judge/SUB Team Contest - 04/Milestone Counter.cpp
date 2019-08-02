#include<bits/stdc++.h>
#define mx             1010
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
int a[mx],b[mx],cpy[mx];
vector<int>ans;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        cpy[i]=b[i];
    }
    for(int i=0;i<m-1;i++){
        a[i]=a[i+1]-a[i];
    }
    for(int i=0;i<n-1;i++){
        b[i]=b[i+1]-b[i];
    }
    int gc=0;
    for(int i=0;i<m-1;i++){
        gc=__gcd(gc,a[i]);
    }
    for(int i=0;i<m-1;i++){
        a[i]/=gc;
    }
    gc=0;
    for(int i=0;i<n-1;i++){
        gc=__gcd(gc,b[i]);
    }
    for(int i=0;i<n-1;i++){
        b[i]/=gc;
    }
    for(int i=0;i<n-m+1;i++){
        bool f=true;
        for(int j=0;j<m-2;j++){
//        cout<<j<<" "<<i<<endl;
//        cout<<b[i+j]<<" "<<b[i+j+1]<<" "<<a[j]<<" "<<a[j+1]<<endl;
            if(a[j]*b[i+j+1]!=b[i+j]*a[j+1]){
                f=false;
                break;
            }
        }
        if(f){
            ans.push_back(cpy[i+1]-cpy[i]);
//            cout<<"ans "<<cpy[i+1]<<" "<<cpy[i]<<endl;
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    if(ans.size()){
        printf("%d\n",ans.size());
        printf("%d",ans[0]);
        for(int i=1;i<ans.size();i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    else{
        printf("0\n");
    }
    return 0;
}
/*
Input:

Output:

*/
