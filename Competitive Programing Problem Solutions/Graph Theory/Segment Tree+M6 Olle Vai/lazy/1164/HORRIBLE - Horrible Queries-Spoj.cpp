#include<bits/stdc++.h>
#define mx 100001
using namespace std;
long long arr[mx];
long long tree[4*mx];
long long lazy[4*mx];
void create_tree(int node,int l,int r){
    if(l>r){
        return;
    }
    if(l==r){
        tree[node]=arr[l];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (l+r)/2;
    create_tree(left,l,mid);
    create_tree(right,mid+1,r);
    tree[node] = tree[left]+tree[right];
}
void update(int node,int l,int r,int i,int j,long long val){
    int left = node*2;
    int right = node*2+1;
    int mid = (l+r)/2;
    if(lazy[node]!=0){
        tree[node]+=lazy[node]*(r-l+1);
        if(l!=r){
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node]=0;
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
    int left = node*2;
    int right = node*2+1;
    int mid = (l+r)/2;
    if(lazy[node]!=0){
        tree[node]+=lazy[node]*(r-l+1);
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
    int t,n,q,a,b,c;
    long long int d;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d %d",&n,&q);
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        create_tree(1,1,n);
        for(int j=1;j<=q;j++){
            scanf("%d",&a);
            if(a==1){
                scanf("%d %d",&b,&c);
                printf("%lld\n",query(1,1,n,b,c));
            }
            else{
                scanf("%d %d %lld",&b,&c,&d);
                update(1,1,n,b,c,d);
            }
        }
    }
    return 0;
}

