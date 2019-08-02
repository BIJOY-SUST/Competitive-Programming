/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define p               pair<int,int>
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
int ans;
int arr[mx],value[4*mx];
p Left[4*mx],Right[4*mx];
void build_tree(int node,int l,int r){
    if(l>r) return;
    if(l==r){
        value[node]=1;
        Left[node]=Right[node]=p(arr[l],1);
        return;
//        left[node].first=right[node].first=arr[l];
//        left[node].second=right[node].second=1;
    }
    int ll=node<<1,rr=(node<<1)+1,mid=(l+r)>>1;
    build_tree(ll,l,mid);
    build_tree(rr,mid+1,r);
    value[node]=max(value[ll],value[rr]);
    Left[node]=Left[ll]; Right[node]=Right[rr];
    if(Left[rr].first==Right[ll].first)
        value[node]=max(value[node],Left[rr].second+Right[ll].second);
    if(Left[ll].first==Left[rr].first) Left[node].second+=Left[rr].second;
    if(Right[ll].first==Right[rr].first) Right[node].second+=Right[ll].second;
}
pair<p,p>query(int node,int l,int r,int i,int j){
    if(l>j||r<i) return make_pair(p(0,0),p(0,0));
    if(l>=i&&r<=j){
        ans=max(ans,value[node]);
        return make_pair(Left[node],Right[node]);
    }
    if(l==r) return make_pair(p(0,0),p(0,0));
    int ll=node<<1,rr=(node<<1)+1,mid=(l+r)>>1;
    pair<p,p>lll=query(ll,l,mid,i,j);
    pair<p,p>rrr=query(rr,mid+1,r,i,j);
    p le1=lll.first,ri1=lll.second;
    p le2=rrr.first,ri2=rrr.second;
    if(ri1.first==le2.first) ans=max(ans,ri1.second+le2.second);
    if(le1.first==le2.first) le1.second+=le2.second;
    if(ri1.first==ri2.first) ri2.second+=ri1.second;
    return make_pair(le1,ri2);
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        printf("Case %d:\n",tc);
        int n,c,q;
        scanf("%d%d%d",&n,&c,&q);
        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
        build_tree(1,1,n);
        for(int i=1;i<=q;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            ans=1;
            query(1,1,n,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
