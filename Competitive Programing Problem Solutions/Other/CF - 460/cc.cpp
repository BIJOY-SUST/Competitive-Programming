#include<bits/stdc++.h>
#define mx             2010

#define ll             long long int

#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<m


using namespace std;
char a[mx][mx];
//bool vis[mx][mx];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    ll mmmmm=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            if(a[i][j]=='.'){
                cnt++;
                if(cnt>=k){
                    mmmmm++;
                }
            }

            if(a[i][j]=='*'){
                cnt=0;
            }

//            cout<<i<<" "<<j<<" "<<cnt<<endl;
        }
    }
    if(k==1) mmmmm=mmmmm;
    else{
    for(int j=0;j<m;j++){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i][j]=='.'){
                cnt++;
                if(cnt>=k){
                    mmmmm++;
                }
            }
            if(a[i][j]=='*'){
                cnt=0;
            }

        }
    }
    }
    cout<<mmmmm<<endl;
    return 0;
}
/*

*/

