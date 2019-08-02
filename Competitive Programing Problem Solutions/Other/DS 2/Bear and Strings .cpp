#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int k=0,ans=0,len=s.length();
    for(int i=0;i<len-3;i++){
        if(s[i]=='b'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='r'){
//            ans+=((i+1)*(len-i-3)-k*(len-i-3));
//            k=i+1;
            if(ans==0) ans+=(i+1)*(len-i-3);
            else ans+=(i-k)*(len-i-3);
            k=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
