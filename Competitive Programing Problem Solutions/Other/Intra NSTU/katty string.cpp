#include<bits/stdc++.h>
using namespace std;
int main(){
//    list<char>s1;
//    list<char>s2;
    string s,ss;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>s>>ss;
        int c=0;
        int a=s.length();
        int b=ss.length();
        int k=min(a,b);
        if(a<=b){
            for(int i=0;i<a;i++){
                for(int j=0;j<b;j++){
                    if(ss[j]==s[i]){
                        c++;
                        break;
                    }
                }
            }
        }
        else{
            for(int i=0;i<b;i++){
                for(int j=0;j<a;j++){
                    if(s[j]==ss[i]){
                        c++;
                        break;
                    }
                }
            }
        }
        if(a<=b) printf("Case %d: %d\n",i,b-c);
        else printf("Case %d: %d\n",i,a-c);
//        for(int i=0;i<s.length();i++){
//            s1.push_back(s[i]);
//        }
//        for(int i=0;i<ss.length();i++){
//            s2.push_back(ss[i]);
//        }
//        s1.unique();
//        s2.unique();
//        int a=s1.size();
//        int b=s2.size();
//        printf("Case %d: %d\n",i,abs(a-b));
//        s1.clear();
//        s2.clear();
    }
    return 0;
}
