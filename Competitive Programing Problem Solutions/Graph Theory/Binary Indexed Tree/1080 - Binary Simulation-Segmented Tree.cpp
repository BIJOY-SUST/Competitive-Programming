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
//#define mx             100001
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
char arr[100001];
int tree[3*100001];
//void constructSEGTree(int node,int b,int e){
//    if(b==e){
//        tree[node]=arr[b];
//        return;
//    }
//    int left = node*2;
//    int right = node*2+1;
//    int mid = (b+e)/2;
//    input(left,b,mid);
//    input(right,mid+1,e);
//    tree[node]=tree[left]+tree[right];
//}
int query(int node,int b,int e,int index){
    if(b==index&&e==index){
        return tree[node];
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    if(index<=mid) return tree[node]+query(left,b,mid,index);
    else return tree[node]+query(right,mid+1,e,index);
}
void update(int node,int b,int e,int i,int j){
    if(i<=b&&j>=e){
        tree[node]++;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    if(j<=mid) update(left,b,mid,i,j);
    else if(i>mid) update(right,mid+1,e,i,j);
    else{
        update(left,b,mid,i,mid);
        update(right,mid+1,e,mid+1,j);
    }
    //tree[node] = tree[left]+tree[right];
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case %d:\n",i);
        memset(tree,0,sizeof(tree));
        scanf("%s",&arr);
        int len=strlen(arr);
        int m;
        scanf("%d",&m);
        for(int i=0;i<len;i++){
            if(arr[i]=='1') update(1,1,len,i+1,i+1);
        }
        while(m--){
            getchar();
            char ch;
            scanf("%c",&ch);
            if(ch=='I'){
                int x,y;
                scanf("%d %d",&x,&y);
                update(1,1,len,x,y);
            }
            else{
                int x;
                scanf("%d",&x);
                printf("%d\n",query(1,1,len,x)%2);
            }
        }
    }
    return 0;
}
