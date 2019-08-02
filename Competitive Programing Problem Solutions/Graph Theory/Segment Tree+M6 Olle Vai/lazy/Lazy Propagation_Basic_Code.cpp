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
long long arr[mx];
long long tree[4*mx];
long long lazy[4*mx];
void create_tree(int node,int l,int r){
    if(l>r){
        return;
    }
    if(l==r){
        tree[node] = arr[l];
        return;
    }
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    create_tree(left,l,mid);
    create_tree(right,mid+1,r);
    tree[node] = tree[left]+tree[right];
}
void update(int node,int l,int r,int i,int j,int val){
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    if(lazy[node]!=0){
        tree[node]+= lazy[node]*(r-l+1);
        if(l!=r){
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(i>r||j<l){
        return;
    }
    if(i<=l&&j>=r){
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
long long query(int node,int l,int r,int i,int j){
    if(l>r||i>r||j<l){
        return 0;
    }
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    if(lazy[node]!=0){
        tree[node]+= lazy[node]*(r-l+1);
        if(l!=r){
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(i<=l&&j>=r){
        return tree[node];
    }
    long long p1=query(left,l,mid,i,j);
    long long p2=query(right,mid+1,r,i,j);
    return p1+p2;
}
int main(){
    int t,n,q,a,b,c,val;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case %d:\n",i);
        scanf("%d %d",&n,&q);
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        create_tree(1,0,n-1);
        for(int j=1;j<=q;j++){
            scanf("%d",&a);
            if(a==1){
                scanf("%d %d",&b,&c);
                printf("%lld\n",query(1,0,n-1,b,c));
            }
            else{
                scanf("%d %d %d",&b,&c,&val);
                update(1,0,n-1,b,c,val);
            }
        }
    }
    return 0;
}

