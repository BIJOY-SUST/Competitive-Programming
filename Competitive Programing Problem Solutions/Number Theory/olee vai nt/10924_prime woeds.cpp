#include<bits/stdc++.h>
//#define mx 1<<15
using namespace std;
//bool mark[mx];
//vector<int>prime;
//void sieve(){
//    memset(mark,true,sizeof(mark));
//    mark[0]=mark[1]=false;
//    for(int i=4;i<=mx;i+=2) mark[i]=false;
//    for(int i=3;i*i<=mx;i+=2){
//        if(mark[i]){
//            for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
//        }
//    }
//    prime.push_back(2);
//    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
//}
bool isprime(int n){
    if(n<1) return false;
    if(n==1) return true;
    for(int i=2;i<=(int)sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    freopen("indev.txt","r",stdin);
//    freopen("outdev.txt","w",stdout);
//    sieve();
    string s;
    while(cin>>s){
        int n=0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='a'&&s[i]<='z'){
                n+=s[i]-96;
            }
            if(s[i]>='A'&&s[i]<='Z'){
                n+=s[i]-38;
            }
        }
//        cout<<n<<'\n';
        if(isprime(n)) cout<<"It is a prime word."<<'\n';
        else cout<<"It is not a prime word."<<'\n';
        s.clear();
    }
    return 0;
}
