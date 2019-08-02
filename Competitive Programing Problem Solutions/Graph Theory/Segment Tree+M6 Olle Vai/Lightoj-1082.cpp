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
int tree[3*mx];
void input(int node,int b,int e){
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    input(left,b,mid);
    input(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j){
    if(i>e||j<b) return mx;
    if(i<=b&&j>=e) return tree[node];
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return min(p1,p2);
}

int main(){
    int t;
    cin>>t;
    for(int a=1;a<=t;a++){
        int n,q;
        scanf("%d%d",&n,&q);
        for(int b=1;b<=n;b++)
            scanf("%d",&arr[b]);

        input(1,1,n);
        printf("Case %d:\n",a);
        for(int b=1;b<=q;b++)
        {
            int i,j;
            scanf("%d%d",&i,&j);
            printf("%d\n",query(1,1,n,i,j));
        }
    }
    return 0;
}

