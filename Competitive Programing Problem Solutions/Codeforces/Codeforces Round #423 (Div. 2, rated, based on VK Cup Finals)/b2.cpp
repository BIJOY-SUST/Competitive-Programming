#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x1,x2,y1,y2=0,c=0;
    bool flag=true;
    cin>>n>>m;
    y1=m-1;
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(flag==true&&arr[i][j]=='B'){
                flag=false;
                x1=i;
            }
            if(arr[i][j]=='B'){
                x2=i;
                int k=j;
                if(k<=y1) y1=k;
                if(k>=y2) y2=k;
                c++;
            }
        }
    }
    if(c==0) cout<<"1"<<endl;
    else{
        int x=x2-x1+1;
        int y=y2-y1+1;
        if(x>n||x>m||y>n||y>m) cout<<"-1"<<endl;
        else if(x>y) cout<<x*x-c<<endl;
        else cout<<y*y-c<<endl;
    }
    return 0;
}
