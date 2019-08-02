#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<cstring>

using namespace std;


int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main(){
    int N,a[10000];
    cin>>N;
    getchar();
    string s;

    while(N--){
        getline(cin,s);
        stringstream ss(s);
        int k=0;
        while(ss>>a[k])
               k++;
        int  ans=0;
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                ans = max(ans,gcd(a[i],a[j]));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
