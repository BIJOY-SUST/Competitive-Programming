#include<bits/stdc++.h>
#define mx 100001
using namespace std;
long long arr[mx];
int tree[4*mx];
bool lazy[4*mx];
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
void update(int node,int l,int r,int i,int j){
    int left = node*2;
    int right = node*2+1;
    int mid = (l+r)/2;
    if(lazy[node]!=0){
        tree[node]=(r-l+1)-tree[node];
        if(l!=r){
            lazy[left]=!lazy[left];
            lazy[right]=!lazy[right];
        }
        lazy[node]=0;
    }
    if(l>r||i>r||j<l){
        return;
    }
    if(i<=l&&j>=r){
        tree[node]=(r-l+1)-tree[node];
        if(l!=r){
            lazy[left]=!lazy[left];
            lazy[right]=!lazy[right];
        }
        return;
    }
    update(left,l,mid,i,j);
    update(right,mid+1,r,i,j);
    tree[node] = tree[left]+tree[right];
}
int query(int node,int l,int r,int i,int j){
    if(l>r||i>r||j<l){
        return 0;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (l+r)/2;
    if(lazy[node]!=0){
        tree[node]=(r-l+1)-tree[node];
        if(l!=r){
            lazy[left]=!lazy[left];
            lazy[right]=!lazy[right];
        }
        lazy[node]=0;
    }
    if(i<=l&&j>=r){
        return tree[node];
    }
    int p1=query(left,l,mid,i,j);
    int p2=query(right,mid+1,r,i,j);
    return p1+p2;
}
int main(){
    int t,n,q,a,b,c;
        scanf("%d %d",&n,&q);
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        create_tree(1,1,n);
        for(int j=1;j<=q;j++){
            scanf("%d",&a);
            if(a==1){
                scanf("%d %d",&b,&c);
                printf("%d\n",query(1,1,n,b,c));
            }
            else{
                scanf("%d %d",&b,&c);
                update(1,1,n,b,c);
            }
        }
    return 0;
}


