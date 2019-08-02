/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define ll             long long int
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
ll arr[mx],tree[4*mx],lazy[4*mx];
void build_tree(int node,int l,int r){
    if(l>r) return;
    if(l==r){
        tree[node]=arr[l];
        return;
    }
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    build_tree(left,l,mid);
    build_tree(right,mid+1,r);
    tree[node] = tree[left]+tree[right];
}
void update(int node,int l,int r,int i,int j,int val){
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    if(lazy[node]!=0){
        tree[node]+=lazy[node]*(r-l+1);
        if(l!=r){
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l>j||r<i) return;
    if(l>=i&&r<=j){
        tree[node]+=(r-l+1)*val;
        if(l!=r){
            lazy[left]+=val;
            lazy[right]+=val;
        }
        return;
    }
    update(left,l,mid,i,j,val);
    update(right,mid+1,r,i,j,val);
    tree[node] = tree[left]+tree[right];
}
ll query(int node,int l,int r,int i,int j){
    if(l>r||l>j||r<i) return 0;
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    if(lazy[node]!=0){
        tree[node]+=lazy[node]*(r-l+1);
        if(l!=r){
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l>=i&&r<=j) return tree[node];
    ll p1 = query(left,l,mid,i,j);
    ll p2 = query(right,mid+1,r,i,j);
    return p1+p2;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        //printf("Case %d:\n",tc);
        int n,q;
        scanf("%d %d",&n,&q);
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        build_tree(1,0,n-1);
        for(int i=1;i<=q;i++){
            int l,r,val;
            scanf("%d%d%d",&l,&r,&val);
            update(1,0,n-1,l,r,val);
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int l;
            scanf("%d",&l);
            printf("%d\n",query(1,0,n-1,l,l));
        }
    }
    return 0;
}

