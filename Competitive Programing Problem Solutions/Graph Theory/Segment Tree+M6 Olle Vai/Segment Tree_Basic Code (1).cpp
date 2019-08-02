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
int arr[mx];
int tree[3*mx];
void input(int node,int l,int r){
    if(l>r) return;
    if(l==r){
        tree[node]=arr[l];
        return;
    }
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    input(left,l,mid);
    input(right,mid+1,r);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int l,int r,int i,int j){
    if(i>r||j<l) return 0;
    if(i<=l&&j>=r) return tree[node];
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    int p1 = query(left,l,mid,i,j);
    int p2 = query(right,mid+1,r,i,j);
    return p1+p2;
}
void update(int node,int l,int r,int i,int newvalue){
    if(i>r||i<l) return;
    if(i<=l&&i>=r){///when l==r==i !!!!!!!!!!
        tree[node] = newvalue;
        return;
    }
    int left=node<<1,right=(node<<1)+1,mid=(l+r)>>1;
    update(left,l,mid,i,newvalue);
    update(right,mid+1,r,i,newvalue);
    tree[node] = tree[left]+tree[right];
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    input(1,1,n);
    update(1,1,n,2,0);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,n,2,2);
    cout<<query(1,1,n,1,3)<<endl;
    return 0;
}
