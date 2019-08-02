#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,p,q,x,c=0,k,l=0,total=0;;
cin>>n>>m;
k=m-1;
char a[n][m];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(c==0 && a[i][j]=='B') p=i,c++;
            if(a[i][j]=='B'){
                q=i;
                x=j;
                if(x<=k) k=x;
                if(x>=l) l=x;
                total++;
            }
}
}
if(total==0) cout<<'1'<<endl;
else{
    p=q-p+1;
    k=l-k+1;
    if(p>m || p>n || k>n || k>m) cout<<"-1"<<endl;
    else if(p>k) cout<<p*p-total<<endl;
    else cout<<k*k-total<<endl;
}
return 0;
}
