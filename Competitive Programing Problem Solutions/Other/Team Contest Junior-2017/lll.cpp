#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        int ss[n];
        for(int j=0;j<n;j++){
            ss[j]=arr[j];
        }
        sort(ss,ss+n);
        int c=0;
        for(int j=0;j<n;j++){
            if(ss[j]!=arr[j]){
                c++;
            }
        }
        printf("Case %d: %d\n",i,c/2);
    }
    return 0;
}
