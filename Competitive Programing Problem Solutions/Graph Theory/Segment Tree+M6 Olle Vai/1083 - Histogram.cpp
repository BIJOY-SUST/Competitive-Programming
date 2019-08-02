#include<bits/stdc++.h>
#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define ll             long long int
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
int n;
int arr[mx],tree[3*mx];
void build_tree(int node,int l,int r){
    if(l>r) return;
    if(l==r){
        tree[node]=l;
        return;
    }
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    build_tree(left,l,mid);
    build_tree(right,mid+1,r);
    if(arr[tree[left]]<arr[tree[right]])
        tree[node]=tree[left];
    else
        tree[node]=tree[right];
//    tree[node]=min(tree[left],tree[right]);
}
int R_M_Q(int node,int l,int r,int i,int j){
    if(l>j||r<i) return -1;
    if(l>=i&&r<=j) return tree[node];
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    int p1 = R_M_Q(left,l,mid,i,j);
    int p2 = R_M_Q(right,mid+1,r,i,j);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    if(arr[p1]<arr[p2]) return p1;
    else return p2;
}
ll large_area(int l,int r){
    if(l>r) return 0;
    if(l==r) return arr[l];
    int min_ind= R_M_Q(1,1,n,l,r);
    ll ans = max((ll)(r-l+1)*arr[min_ind],max(large_area(l,min_ind-1),large_area(min_ind+1,r)));
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
        build_tree(1,1,n);
//        for(int i=1;i<=20;i++){
//            printf("node %d: %d\n",i,tree[i]);
//        }
        ll ans=large_area(1,n);
        printf("Case %d: %lld\n",tc,ans);
    }
    return 0;
}











































///AC But Time Limit..............
///*
//BIJOY
//CSE-25th Batch
//Shahjalal University of Science and Technology
//*/
//#include<bits/stdc++.h>
////#define pi             3.141592653589793238462643383
////#define pi             2*acos(0.0)
////#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define ll             long long int
////#define llu            unsigned long long int
//#define mx             100001
////#define mod            100000007
////const long long inf =  1e15;
///*----------------------Graph Moves------------------*/
////const int fx[]={+1,-1,+0,+0};
////const int fy[]={+0,+0,+1,-1};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
////const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
////const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
///*---------------------------------------------------*/
///*-----------------------Bitmask---------------------*/
////int biton(int n,int pos){return n=n|(1<<pos);}
////int bitoff(int n,int pos){return n=n&~(1<<pos);}
////bool check(int n,int pos){return (bool)(n&(1<<pos));}
///*---------------------------------------------------*/
//using namespace std;
//int n;
//int arr[mx],tree[3*mx];
//void build_tree(int node,int l,int r){
//    if(l>r) return;
//    if(l==r){
//        tree[node]=arr[l];
//        return;
//    }
//    int left = node<<1;
//    int right = (node<<1)+1;
//    int mid = (l+r)>>1;
//    build_tree(left,l,mid);
//    build_tree(right,mid+1,r);
//    tree[node]=min(tree[left],tree[right]);
//}
//int R_M_Q(int node,int l,int r,int i,int j){
//    if(l>j||r<i) return -1;
//    if(l==r) return l;
//    int left = node<<1;
//    int right = (node<<1)+1;
//    int mid = (l+r)>>1;
//    int p1 = R_M_Q(left,l,mid,i,j);
//    int p2 = R_M_Q(right,mid+1,r,i,j);
//    if(p1==-1) return p2;
//    if(p2==-1) return p1;
//    if(arr[p1]<arr[p2]) return p1;
//    else return p2;
//}
//ll large_area(int l,int r){
//    if(l>r) return 0;
//    if(l==r) return arr[l];
//    int min_ind= R_M_Q(1,1,n,l,r);
//    ll ans = max((ll)(r-l+1)*arr[min_ind],max(large_area(l,min_ind-1),large_area(min_ind+1,r)));
//    return ans;
//}
//int main(){
////    freopen("Input.txt","r",stdin);
////    freopen("Output.txt","w",stdout);
//    int t;
//    scanf("%d",&t);
//    for(int tc=1;tc<=t;tc++){
//        memset(arr,0,sizeof(arr));
//        memset(tree,0,sizeof(tree));
//        scanf("%d",&n);
//        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
//        build_tree(1,1,n);
////        for(int i=1;i<=20;i++){
////            printf("node %d: %d\n",i,tree[i]);
////        }
//        ll ans=large_area(1,n);
//        printf("Case %d: %lld\n",tc,ans);
//    }
//    return 0;
//}
