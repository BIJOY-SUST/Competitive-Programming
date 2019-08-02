#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        map<char,int>m;
        m.clear();
        double sum=0;
        char s[10001];
        memset(s,0,sizeof(s));
        int M;
        cin>>M;
        for(int j=1;j<=M;j++){
            char ch;
            int value;
            cin>>ch>>value;
            m[ch]=value;
        }
        long long int h,k;
        scanf("%lld\n",&h);
        for(k=1;k<=h;k++){
            gets(s);
            for(int n=0;n<strlen(s);n++){
                if(m[s[n]]>0){
                    sum+=m[s[n]];
                }
            }
        }
        printf("%.2lf$\n",sum/100);
    }
    return 0;
}
