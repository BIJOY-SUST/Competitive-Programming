#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int T,N;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>N;
        int a[N];
        int high = 0, low = 0;
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        for(int j=0;j<N-1;j++){
            if(a[j]<a[j+1]){
                high++;
            }
            else if(a[j]>a[j+1]){
                low++;
            }
        }
        printf("Case %d: %d %d\n",i,high,low);
    }
}
