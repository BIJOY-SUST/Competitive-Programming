#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[100][100];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*m;j++){
            cin>>a[i][j];
        }
    }
    int c = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*m-1;j=j+2){
            if(a[i][j]==1||a[i][j+1]==1){
                c++;
            }
        }
    }
    cout<<c<<endl;
    return 0;
}
