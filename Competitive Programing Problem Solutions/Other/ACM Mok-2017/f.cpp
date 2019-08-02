#include<bits/stdc++.h>
using namespace std;
bool arr[1000001];
int a[30];
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,m;
        scanf("%d %d",&n,&m);
        memset(arr,false,sizeof(arr));
        memset(a,0,sizeof(a));
        for(int j=0;j<n;j++){
            scanf("%d",&a[j]);
        }
        sort(a,a+n);
        for(int j=0;j<n;j++){
            int p=a[j];
            int ans=p;
            while(p<=m){
                arr[p]=true;
                p+=ans;
            }
        }
        int c=0;
        for(int j=1;j<=m;j++){
            if(arr[j]==true) c++;
        }
        printf("Case %d: %d\n",i,c);
    }
    return 0;
}
