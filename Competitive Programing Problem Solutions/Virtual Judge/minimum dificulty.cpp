#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,a[10000];
    while(scanf("%d",&n)!=EOF){
        for (int i=0; i<n;i++){
            cin>>a[i];
        }
        int minimum=10000;
        for(int i=1;i<n-1;i++){
            int maximum=-10000;
            for(int j=0;j<n-1;j++){
                if(i==j){
                    maximum = max(maximum, a[j+1]-a[i-1]);
                }
                else{
                    maximum = max(maximum, a[j+1]-a[j]);
                }
            }
            minimum = min(minimum, maximum);
        }
        cout<<minimum<<endl;
    }
    return 0;
}
