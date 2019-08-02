#include<bits/stdc++.h>
using namespace std;
#define mx 4000001
int arr[mx];

class node{
public:
    long int sum,prog;
}tree[mx*3];

void make_segment_tree(long long int node,long long int l,long long int r){
    if(l==r){
        return;
    }
    long long int left = node*2;
    long long int right = (node*2)+1;
    long long int mid = (l+r)/2;
    make_segment_tree(left,l,mid);
    make_segment_tree(right,mid+1,r);
    tree[node].sum = tree[left].sum+tree[right].sum;
}

void update(long long int node,long long int l,long long int r,long long int i,long long int j,long long int x){
    if(i>r||j<l){
        return;
    }
    if(i<=l&&j>=r){
        tree[node].sum+=(r-l+1)*x;
        tree[node].prog+=x;
        return;
    }
    long long int left = node*2;
    long long int right = (node*2)+1;
    long long int mid = (l+r)/2;
    update(left,l,mid,i,j,x);
    update(right,mid+1,r,i,j,x);
    tree[node].sum = tree[left].sum+tree[right].sum+(r-l+1)*tree[node].prog;
}

int query(long long int node,long long int l,long long int r,long long int i,long long int j,long long int carry=0){
    if(i>r||j<l){
        return 0;
    }
    if(i<=l&&j>=r){
        return tree[node].sum+carry*(r-l+1);
    }
    long long int left = node*2;
    long long int right = (node*2)+1;
    long long int mid = (l+r)/2;
    long long int p1 = query(left,l,mid,i,j,carry+tree[node].prog);
    long long int p2 = query(right,mid+1,r,i,j,carry+tree[node].prog);
    return p1+p2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t,n,q,a,b,c,d,i;
    cin>>t;
    while(t--){
    cin>>n>>q;
    for(i=1;i<=n;i++){
        arr[i]=0;
    }
    make_segment_tree(1,1,n);
    while(q--){
        cin>>a;
        if(a==0){
            cin>>b>>c>>d;
            update(1,1,n,b,c,d);
        }
        else{
            cin>>b>>c;
            cout<<query(1,1,n,b,c)<<"\n";
        }
    }
    }
    return 0;
}

