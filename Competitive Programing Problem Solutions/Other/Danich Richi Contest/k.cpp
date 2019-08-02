#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        string s;
        cin>>s;
        int x,y=1;
        s[0]='A';
//        bool flag[100001];
//        memset(flag,false,sizeof(flag));
//        flag[0]=true;
//        s[1]='A';
        for(int i=1;i<s.length();i=x+y){
            s[i]='A';
//            flag[i]=true;
            x=y;
            y=i;
        }
//        cout<<s<<'\n';
        int b=0,m=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='B') b++;
            else if(s[i]=='M') m++;
        }
        if(b>m) printf("Case #%d: Aaj Kemon Bodh Korcho\n",k);
        else if(m>b) printf("Case #%d: Hala Madrid\n",k);
        else printf("Case #%d: Meh :\\\n",k);
//        else cout<<"Case #"<<k<<": Meh :\\"<<'\n';
        s.clear();
    }
    return 0;
}
//&&flag[i]==true
