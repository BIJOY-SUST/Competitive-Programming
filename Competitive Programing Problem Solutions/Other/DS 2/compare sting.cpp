#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    bool flag=true;
    if(s1.length()!=s2.length()){
        printf("NO\n");
        return 0;
    }
    vector<int>v;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]) v.push_back(i);
    }
    if(v.size()!=2){
        printf("NO\n");
        return 0;
    }
    swap(s1[v[0]],s1[v[1]]);
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}


























































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
//        m[s1[i]]++;
//        mm[s2[i]]++;
//    }
//    for(int i=0;i<s1.length();i++){
//        if(m[s1[i]]==mm[s1[i]]&&s1[i]!=s2[i]){
////            continue;
//            c++;
//        }
////        else{
////            flag=false;
////        }
//    }
//    if(c==2) printf("YES\n");
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
