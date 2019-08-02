#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;


int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main(){
    int N,M;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>M;
        int a[100000];
        for(int j=0;j<M;j++){
            cin>>a[j];
        }
        sort(a,a+M);
        int  ans=0;
        for(int i=0;i<M-1;i++){
            for(int j=i+1;j<M;j++){
                ans = max(ans,gcd(a[i],a[j]));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
