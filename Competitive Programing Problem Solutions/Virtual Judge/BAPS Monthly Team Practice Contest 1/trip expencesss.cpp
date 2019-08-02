#include<bits/stdc++.h>
using namespace std;
const int maxn = 300;
long long int mat[maxn+5][maxn+5];
int node,edge, p_next[maxn+5][maxn+5];
bool arr[maxn+5][maxn+5];
void floyd()
{
    for(int i=1;i<=node;i++){
        for(int j=1;j<=node;j++){
            for(int k=1;k<=node;k++){
                if(mat[j][k] > mat[j][i] + mat[i][k]){
                    mat[j][k] = mat[j][i] + mat[i][k];
                    p_next[j][k] = p_next[j][i]+p_next[i][k];
                }
                else if(mat[j][k] == mat[j][i] + mat[i][k]){
                    p_next[j][k] = min(p_next[j][k],p_next[j][i]+p_next[i][k]);
                }
            }
        }
    }
}
int main()
{
    freopen("trip.in","r",stdin);
    freopen("trip.out","w",stdout);
    for(int i=1;i<=maxn;i++){
        for(int j=1;j<=maxn;j++){
            if(i!=j) mat[i][j]=1e15;
            //p_next[i][j]=1e15;
        }
    }
    int x,y,z;
    scanf("%d%d",&node,&edge);
    for(int i=0;i<edge;i++){
        scanf("%d%d%d",&x,&y,&z);
        if(mat[x][y]>z) mat[x][y] = z;
        if(mat[y][x]>z) mat[y][x] = z;
        p_next[x][y]=1;
        p_next[y][x]=1;
    }
    floyd();
    double ans=0;
    for(int i=1;i<node;i++){
        for(int j=i+1;j<=node;j++){
            ans+=p_next[i][j];
//            cout<<i<<" "<<j<<" "<<p_next[i][j]<<endl;
        }
    }
    node=(double)(node*node-node)/2.0;
    ans = (double)(ans/node);
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

