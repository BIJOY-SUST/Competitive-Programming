#include<bits/stdc++.h>
using namespace std;
bool test[28];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s1;
    string s2;
    cin>>s1>>s2;
    for(int g=0;g<s1.length();g++){
        test[s1[g]-'a']=true;
    }
    cin>>n;
    for(int k=1;k<=n;k++){
        string s3;
        cin>>s3;
        if(s2.length()-1>s3.length()){
            cout<<"NO\n";
            continue;
        }
        int i,j;
        bool flag = false;
        for(i=0,j=0;i<s2.length()&&j<s3.length();i++,j++){
            if(s2[i]=='?'){
                if(!test[s3[j]-'a']){
                    flag=true;
                    cout<<"NO\n";
                    break;
                }
            }
            else if(s2[i]=='*'){
                if(s2.length()-1==s3.length()){
                    j--;
                }
                else{
                    bool m = false;
                    for(int h=j;h<=j+s3.length()-s2.length();h++){
                        if(test[s3[h]-'a']){
                            m=true;
                        }
                    }
                    if(m){
                        flag=true;
                        cout<<"NO\n";
                        break;
                    }
                    else{
                        j=j+s3.length()-s2.length();
                    }
                }
            }
            else if(s2[i]!=s3[j]){
                flag=true;
                cout<<"NO"<<"\n";
                break;
            }
        }
        if(flag==false){
            if(j==s3.length()&&(i==s2.length()||(i==s2.length()-1&&s2[i]=='*'))){
                cout<<"YES"<<"\n";
            }
            else{
                cout<<"NO"<<"\n";
            }
        }
    }
    return 0;
}
