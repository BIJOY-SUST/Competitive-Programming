#include<bits/stdc++.h>
#include<string>

using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        for(int i=1;i<s.length();i++){
            if(s.length()/2==0){
                string ss=substr(0,s.length()/2);
                string sss=substr(s.length()/2,s.length());
                string ssss=reverse(sss,sss+sss.length());
                if(ss==sss||ss==ssss){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else if(s.length()/2==1){
                string ss=substr(0,(s.length()-1)/2);
                string sss=substr((s.length()+1)/2,s.length());
                string ssss=reverse(sss,sss+sss.length());
                if(ss==sss||ss==ssss){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}
