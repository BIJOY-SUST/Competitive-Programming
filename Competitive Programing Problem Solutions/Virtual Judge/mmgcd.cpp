#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;


int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main(){
    int N;
    cin>>N;
    string s;
    while(N--){
        cin>>s;
        int c=1;
        int len = s.size();
        for(int j=0; j<len;j++) {
            if(s[j] == ' '){
                c++;
            }
        }
        sort(s,s+c);
        int  ans=0;
        for(int i=0;i<c-1;i++){
            for(int j=i+1;j<c;j++){
                ans = max(ans,gcd(s[i],s[j]));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
