#include<bits/stdc++.h>
#define st_arr(a,b) memset(a,b,sizeof(a))
#define pp  make_pair
#define pb  push_back
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    for(int i = 0 ; i < n; i++)
    {
        int f = s.find("bear",i);
        if (f!=555)
            ans += n-f-3;
    }
    cout << ans << '\n';
    return 0;
}


















































//#include<bits/stdc++.h>
//using namespace std;
//map<char,int>m;
//map<char,int>mm;
//int main(){
//    string s1,s2;
//    cin>>s1>>s2;
//    string s3,s4;
//    int c=0;
//    bool flag=true;
//    if(s1.length()!=s2.length()){
//        printf("NO\n");
//        return 0;
//    }
//    for(int i=0;i<s1.length();i++){
//        if(s1[i]!=s2[i]){
//            c++;
//            s3=s1.at(i);
//            s3+=s2.at(i);
//        }
//    }
//    if(c==2){
//        if(s3[0]==s3[2]&&s3[1]==s3[3]){
//            flag=false;
//        }
//    }
//    if(!flag) printf("YES\n");
//    else printf("NO\n");
//    return 0;
//}







//#include<bits/stdc++.h>
//using namespace std;
//map<char,int>m;
//map<char,int>mm;
//int main(){
//    string s1,s2;
//    cin>>s1>>s2;
//    bool flag=true;
//    int c=0;
//    if(s1.length()!=s2.length()){
//        printf("NO\n");
//        return 0;
//    }
//    for(int i=0;i<s1.length();i++){
//        if(s1[i]!=s2[i]) c++;
//    }
////    for(int i=0;i<s1.length();i++){
////        m[s1[i]]++;
////        mm[s2[i]]++;
////    }
////    for(int i=0;i<s1.length();i++){
////        if(m[s1[i]]==mm[s1[i]]){
////            continue;
////        }
////        else{
////            flag=false;
////        }
////    }
//    if(c<=2) printf("YES\n");
//    else printf("NO\n");
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    string s1,s2;
//    cin>>s1>>s2;
//    if(s1.length()!=s2.length()){
//        printf("NO\n");
//        return 0;
//    }
//    bool flag=true;
//    for(int i=0;i<s1.length()-1;i+=2){
//        if(s1[i]==s2[i+1]&&s1[i+1]==s2[i]){
//            continue;
//        }
//        else{
//            flag=false;
//            break;
//        }
//    }
//    if(flag) printf("YES\n");
//    else printf("NO\n");
//    return 0;
//}







































//#include<bits/stdc++.h>
//#define mx 1000001
//using namespace std;
//int main(){
//    int n;
//    scanf("%d",&n);
//    string s;
//    string s1="vaporeon",s2="jolteon",s3="flareon",s4="espeon",s5="umbreon",s6="leafeon",s7="glaceon",s8="sylveon";
//    cin>>s;
//    if(n==6){
//        cout<<s4<<endl;
//        return 0;
//    }
//    if(n==8){
//        cout<<s1<<endl;
//        return 0;
//    }
//    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
////    cout<<s.length()<<endl;
//    for(int i=0;i<s.length();i++){
//    if(s[i]!='.'){
//        if(s[i]==s1[i]) a++;
//        if(s[i]==s2[i]) b++;
//        if(s[i]==s3[i]) c++;
//        if(s[i]==s4[i]) d++;
//        if(s[i]==s5[i]) e++;
//        if(s[i]==s6[i]) f++;
//        if(s[i]==s7[i]) g++;
//        if(s[i]==s8[i]) h++;
//    }
//    }
////    cout<<a<<b<<c<<d<<e<<f<<g<<h<<endl;
//    int ans=max(max(max(max(max(max(max(a,b),c),d),e),f),g),h);
//    if(ans>0){
//         if(ans==a) cout<<s1<<endl;
//    else if(ans==b) cout<<s2<<endl;
//    else if(ans==c) cout<<s3<<endl;
//    else if(ans==d) cout<<s4<<endl;
//    else if(ans==e) cout<<s5<<endl;
//    else if(ans==f) cout<<s6<<endl;
//    else if(ans==g) cout<<s7<<endl;
//    else if(ans==h) cout<<s8<<endl;
//    }
//    else{
//        if(s.length()==6) cout<<s4<<endl;
//        else if(s.length()==8) cout<<s1<<endl;
//        else cout<<s2<<endl;
//    }
//    return 0;
//}
