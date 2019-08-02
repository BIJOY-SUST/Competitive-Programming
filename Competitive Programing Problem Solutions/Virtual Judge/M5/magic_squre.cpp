#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    bool flag=true;
    int grid[100][100];
    while(cin>>n){
        if(flag==false){
            cout<<endl;
        }
        flag=false;
        memset(grid,0,sizeof(grid));
        int s=n*(n*n+1)/2;
        int i,j;
        i=0;
        j=n/2;
        for(int v=1;v<=n*n;v++){
            grid[i][j]=v;
            if(v%n==0){
                i++;
            }
            else{
                if(i==0){
                    i=n-1;
                    j++;
                }
                else if(i>0){
                    i--;
                    j++;
                    if(j>n-1){
                        j=0;
                    }
                }
            }
        }
        cout<<"n="<<n<<", sum="<<s<<endl;
        if(n==3){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<" ";
                printf("%1d",grid[i][j]);
                //cout<<grid[i][j];
            }
            cout<<endl;
        }
        }
        if(n>=5&&n<=9){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<" ";
                printf("%2d",grid[i][j]);
                //cout<<grid[i][j];
            }
            cout<<endl;
        }
        }
        if(n>9){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<" ";
                printf("%3d",grid[i][j]);
                //cout<<grid[i][j];
            }
            cout<<endl;
        }
        }

    }
    return 0;
}
