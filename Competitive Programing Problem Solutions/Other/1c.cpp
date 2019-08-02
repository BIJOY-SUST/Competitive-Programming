#include<bits/stdc++.h>
using namespace std;
int main(){
    int l=0,d=0,v=0,c=0;
    char str[10000];
    gets(str);
    int len = strlen(str);
    for(int i=0;i<len;i++){
        if(isalpha(str[i])){
            l++;
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'){
                v++;
            }
            else{
                c++;
            }
        }
        else{
            d++;
        }
    }
    cout<<l<<" "<<d<<" "<<v<<" "<<c<<" "<<endl;
    return 0;
}
