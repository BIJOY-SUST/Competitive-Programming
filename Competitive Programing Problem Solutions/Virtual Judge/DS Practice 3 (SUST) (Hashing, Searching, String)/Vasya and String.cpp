/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             100001
//#define mod            100000007
//const long long inf =  1e15;
/*----------------------Graph Moves------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
/*---------------------------------------------------*/
/*-----------------------Bitmask---------------------*/
//int biton(int N,int pos){return N=N(1<<pos);}
//int bitoff(int N,int pos){return N=N&~(1<<pos);}
//bool check(int N,int pos){return (bool)(N&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
int arr[mx];
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,k,ans=0;
    scanf("%d %d",&n,&k);
    string s;
    cin>>s;
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++){
        if(s[i]=='a') arr[i+1]=arr[i];
        else arr[i+1]=arr[i]+1;
    }
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(arr[mid]-arr[i-1]<=k) l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,l-i);
    }
    for(int i=0;i<n;i++){
        if(s[i]=='b') arr[i+1]=arr[i];
        else arr[i+1]=arr[i]+1;
    }
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(arr[mid]-arr[i-1]<=k) l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,l-i);
    }
    printf("%d\n",ans);
    return 0;
}
///Teach from google........
