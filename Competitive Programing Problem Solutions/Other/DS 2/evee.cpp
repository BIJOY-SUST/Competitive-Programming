#include<bits/stdc++.h>
#define mx 1000001
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    string s;
    string s1="vaporeon",s2="jolteon",s3="flareon",s4="espeon",s5="umbreon",s6="leafeon",s7="glaceon",s8="sylveon";
    cin>>s;
    if(n==6){
        cout<<s4<<endl;
        return 0;
    }
    if(n==8){
        cout<<s1<<endl;
        return 0;
    }
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
//    cout<<s.length()<<endl;
    for(int i=0;i<s.length();i++){
    if(s[i]!='.'){
        if(s[i]==s1[i]) a++;
        if(s[i]==s2[i]) b++;
        if(s[i]==s3[i]) c++;
        if(s[i]==s4[i]) d++;
        if(s[i]==s5[i]) e++;
        if(s[i]==s6[i]) f++;
        if(s[i]==s7[i]) g++;
        if(s[i]==s8[i]) h++;
    }
    }
//    cout<<a<<b<<c<<d<<e<<f<<g<<h<<endl;
    int ans=max(max(max(max(max(max(max(a,b),c),d),e),f),g),h);
    if(ans>0){
         if(ans==a) cout<<s1<<endl;
    else if(ans==b) cout<<s2<<endl;
    else if(ans==c) cout<<s3<<endl;
    else if(ans==d) cout<<s4<<endl;
    else if(ans==e) cout<<s5<<endl;
    else if(ans==f) cout<<s6<<endl;
    else if(ans==g) cout<<s7<<endl;
    else if(ans==h) cout<<s8<<endl;
    }
    else{
        if(s.length()==6) cout<<s4<<endl;
        else if(s.length()==8) cout<<s1<<endl;
        else cout<<s2<<endl;
    }
    return 0;
}

