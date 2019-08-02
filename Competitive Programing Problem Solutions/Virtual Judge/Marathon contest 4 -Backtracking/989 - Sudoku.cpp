#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             100001
//#define mod            100000007
#define Unassigned     0
//const long long inf =  1e15;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//-----------------------------------------------------
//-----------------------Bitmask-----------------------
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//-----------------------------------------------------
using namespace std;
int grid[10][10];
int N,m;
bool UsedInRow(int row,int num){
    for(int col=0;col<N;col++) if(grid[row][col]==num) return true;
    return false;
}
bool UsedInCol(int col,int num){
    for(int row=0;row<N;row++) if(grid[row][col]==num) return true;
    return false;
}
bool UsedInBox(int row_0,int col_0,int num){
    for(int row=0;row<m;row++) for(int col=0;col<m;col++)
        if(grid[row+row_0][col+col_0]==num) return true;
    return false;
}
bool isSafe(int row,int col,int num){
    return !UsedInRow(row,num)&&!UsedInCol(col,num)&&!UsedInBox(row-row%m,col-col%m,num);
}
bool FindUnassignedLocation(int &row,int &col){
    for(row=0;row<N;row++) for(col=0;col<N;col++)
        if(grid[row][col]==Unassigned) return true;
    return false;
}
bool B_T_Sudoku(){
    int row,col;
//    cout<<row<<" "<<col<<endl;
    if(!FindUnassignedLocation(row,col)) return true;
    for(int num=1;num<=N;num++){
        if(isSafe(row,col,num)){
            grid[row][col]=num;
            if(B_T_Sudoku()) return true;
            grid[row][col]=Unassigned;
        }
    }
    return false;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    bool ff=false;
    while(scanf("%d",&N)!=EOF){
        if(ff) printf("\n");
        ff=true;
        m=N;
        N=N*N;
        memset(grid,0,sizeof(grid));
        for(int i=0;i<N;i++) for(int j=0;j<N;j++)
            scanf("%d",&grid[i][j]);
        bool ans=B_T_Sudoku();
        if(ans){
            for(int row=0;row<N;row++){
                for(int col=0;col<N;col++){
                    if(col!=N-1) printf("%d ",grid[row][col]);
                    else printf("%d",grid[row][col]);
                }
                printf("\n");
            }
        }
        else printf("NO SOLUTION\n");
    }
    return 0;
}
