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
vector<int>arr;
bool func(int mid,int k){
    int sum=0,cnt=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>mid){
            cnt = 10010;
            break;
        }
        else if(sum+arr[i]>mid){
            cnt++;
            sum=arr[i];
        }
        else if(sum+arr[i]==mid){
            cnt++;
            sum=0;
        }
        else sum+=arr[i];
    }
    if(sum>0)cnt++;
    if(cnt<=k+1) return true;
    else return false;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        arr.clear();
        int n,k,sum=0;
        scanf("%d%d",&n,&k);
        for(int i=0;i<=n;i++){
            int h; scanf("%d",&h);
            arr.push_back(h);
            sum+=h;
        }
        int l=0,h=sum,ans;
        while(l<=h){
            int mid=(l+h)>>1;
            if(func(mid,k)){
                h=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        printf("Case %d: %d\n",cs,ans);
        sum=0;
        int cnt=0;
        for(int i=0;i<=n;i++){
            if(sum+arr[i]>ans){
                printf("%d\n",sum);
                cnt++;
                sum=arr[i];
            }
            else if(sum+arr[i]==ans||n-i==k-cnt){
                printf("%d\n",sum+arr[i]);
                cnt++;
                sum=0;
            }
            else sum+=arr[i];
        }
    }
    return 0;
}
/**
Input:

Output:

**/
