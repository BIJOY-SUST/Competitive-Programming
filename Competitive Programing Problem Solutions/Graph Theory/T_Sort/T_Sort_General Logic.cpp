/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             10001
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
int n,m;
int order[mx][mx];
map<int,int>indegree;
map<int,int>taken;
void T_SORT(){
    vector<int>task;
    int j;
    bool flag=true;
    for(int i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(!taken[j] && !indegree[j]){
                taken[j]=1;
                task.push_back(j);
                for(int k=1;k<=n;k++){
                    if(!taken[k]&&order[j][k]) indegree[k]--;
                }
                break;
            }
        }
        if(j==n+1) flag=false;
    }
    if(flag==true){
        vector<int>::iterator it;
        for(it=task.begin();it!=task.end();it++){
            cout<<*it<<" ";
        }
        printf("\n");
        task.clear();
    }
    else{
        printf("This is no solution\n");
        task.clear();
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    while(scanf("%d%d",&n,&m)==2&&n!=0&&m!=0){
//        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++){
            indegree[i]=0;
            taken[i]=0;
        }
        for(int i=1;i<=m;i++){
            int u,v;scanf("%d%d",&u,&v);
            order[u][v]=1;
            indegree[v]++;
        }
        T_SORT();
        memset(order,0,sizeof(order));
        indegree.clear();
        taken.clear();
    }
    return 0;
}
/*
Sample Input
5 4
1 2
2 3
1 3
1 5
0 0
Sample Output
1 4 2 5 3
*/
