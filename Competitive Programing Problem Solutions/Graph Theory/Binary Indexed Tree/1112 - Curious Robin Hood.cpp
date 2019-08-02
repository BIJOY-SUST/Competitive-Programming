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
#define ui unsigned int
using namespace std;
//vector<int>elements;
//vector<int>BITree;
int elements[100001];
int BITree[100001];
int n;
int getSum(ui index){
    int sum=0;
    index=index+1;
    while(index>0){
        sum+=BITree[index];
        index-=index&(-index);
    }
    return sum;
}
int rangeQuery(ui u,ui v){
    return getSum(v)-getSum(u-1);
}
void updateBIT(ui index,int value){
    index=index+1;
    while(index<=n){
        BITree[index]+=value;
        index+=index&(-index);
    }
}
void updateBIT_decress(ui index,int value){
    index=index+1;
    while(index<=n){
        BITree[index]-=value;
        index+=index&(-index);
    }
}
void constructBITree(){
    for(int i=1;i<=n;i++){
        //BITree.push_back(0);
        BITree[i]=0;
    }
    for(int i=0;i<n;i++){
        updateBIT(i,elements[i]);
    }
}
int main(){
//    freopen("01.txt","r",stdin);
//    freopen("02.txt","w",stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        memset(elements,0,sizeof(elements));
        memset(BITree,0,sizeof(BITree));
        printf("Case %d:\n",i);
        int q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++){
            int k;
            scanf("%d",&k);
            elements[i]=k;
            //elements.push_back(k);
        }
        constructBITree();
        while(q--){
            int a;
            scanf("%d",&a);
            if(a==1){
                ui h;
                scanf("%d",&h);
//                updateBIT(h,elements[h]);
                updateBIT_decress(h,elements[h]);
                printf("%d\n",elements[h]);
                elements[h]=0;
            }
            else if(a==2){
                ui h,k;
                scanf("%d %d",&h,&k);
                updateBIT(h,k);
                elements[h]=elements[h]+k;
            }
            else if(a==3){
                ui h,k;
                scanf("%d %d",&h,&k);
//                if(h!=0)
                printf("%d\n",rangeQuery(h,k));
                //else printf("%d\n",getSum(k));
            }
        }
//        elements.clear();
//        BITree.clear();
    }
    return 0;
}
