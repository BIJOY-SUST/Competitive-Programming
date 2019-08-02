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
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
int n,d;
int arr[mx];
class tree{
public:
    int maxi,mini;
};
tree seg_tree[3*mx];
void build_tree(int node,int l,int r){
    if(l>r) return;
    if(l==r){
        seg_tree[node].maxi=arr[l];
        seg_tree[node].mini=arr[l];
        return;
    }
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    build_tree(left,l,mid);
    build_tree(right,mid+1,r);
    seg_tree[node].maxi=max(seg_tree[left].maxi,seg_tree[right].maxi);
    seg_tree[node].mini=min(seg_tree[left].mini,seg_tree[right].mini);
}
tree query(int node,int l,int r,int i,int j){
    if(i>r||j<l){
        tree ret;
        ret.maxi=0;
        ret.mini=INT_MAX;
        return ret;
    }
    if(i<=l&&j>=r) return seg_tree[node];
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    tree ret1=query(left,l,mid,i,j);
    tree ret2=query(right,mid+1,r,i,j);
    tree ret3;
    ret3.maxi=0,ret3.mini=INT_MAX;
    ret3.maxi=max(ret3.maxi,max(ret1.maxi,ret2.maxi));
    ret3.mini=min(ret3.mini,min(ret1.mini,ret2.mini));
    return ret3;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        build_tree(1,1,n);
        int ans=0,st=1;
        while(d<=n){
            tree ret=query(1,1,n,st,d);
            int diff=ret.maxi-ret.mini;
            ans=max(ans,diff);
            st++;
            d++;
        }
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
