#include<bits/stdc++.h>
using namespace std;
const int maxn = 300;
long long int mat[maxn+5][maxn+5];
int node,edge, NEXT[maxn+5][maxn+5];
long long int cnt=0;
vector<int>path;
bool arr[maxn+5][maxn+5];
void floyd()
{
    //int i,j,k;
    for(int i=0;i<=node;i++){
        for(int j=0;j<=node;j++){
            NEXT[i][j] = j;
        }
    }
    for(int i=1;i<=node;i++){
        for(int j=1;j<=node;j++){
            for(int k=1;k<=node;k++){
                if(mat[j][k] > mat[j][i] + mat[i][k]){
                    mat[j][k] = mat[j][i] + mat[i][k];
                    NEXT[j][k] = NEXT[j][i];
                }
            }
        }
    }
}

void findpath(int i,int j)
{
    path.clear();
    path.push_back(i);
    while(i != j){
        i = NEXT[i][j];
        path.push_back(i);
    }
    cnt += path.size()-1;
}
int main()
{
    freopen("trip.in","r",stdin);
    freopen("trip.out","w",stdout);
    for(int i=0;i<=maxn;i++){
        for(int j=0;j<=maxn;j++){
            if(i==j) mat[i][j]=0;
            else mat[i][j] = (1<<29);
        }
    }
    int x,y,z;
    //cin>>node>>edge;
    scanf("%d%d",&node,&edge);
    for(int i=0;i<edge;i++){
//        cin>>x>>y>>z;
        scanf("%d%d%d",&x,&y,&z);
        if(mat[x][y]>z) mat[x][y] = z;
        if(mat[y][x]>z) mat[y][x] = z;
    }
    floyd();
    for(int i=1;i<=node;i++){
        for(int j=1;j<=node;j++){
            if(i != j){
                if(!arr[i][j]){
                    findpath(i,j);
                    arr[i][j]=true;
                    arr[j][i]=true;
                }
            }
        }
    }

    double ans = (double)(cnt*1.0)/((node*node-node)/2.0);
    printf("%.9f\n",ans);
    return 0;
}
/*
4 7
1 2 5
1 2 10
1 3 3
2 3 2
1 4 2
3 4 1
2 4 5
*/

