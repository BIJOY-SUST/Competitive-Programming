#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
//string replaceAll(string subject,  string ss,string rr) {
//    size_t pos = 0;
//    while((pos = subject.find(ss, pos)) != string::npos) {
//         subject.replace(pos, ss.length(), rr);
//         pos += rr.length();
//    }
//    return subject;
//}
void replaceAll(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        string s;
//        getchar();
        getline(cin,s);
//        getchar();
//        string s1;
//        string s1,s2,s3,s4;
        replaceAll(s,"cheater","charming");
        replaceAll(s,"kala para na","khela pare");
        replaceAll(s,"appy nyc lagca","vaiya you are very handsome");
        replaceAll(s,"programmer","man with love and life");
        cout<<s<<endl;
//        s.clear();
    }
    return 0;
}
