#include<bits/stdc++.h>
using namespace std;
string s;
//void replaceAll(string &s,const string &search,const string &replace){
//    for(size_t pos = 0; ; pos += replace.length()){
//        pos = s.find( search, pos );
//        if( pos == string::npos ) break;
//        s.erase( pos, search.length() );
//        s.insert( pos, replace );
//    }
//}
void replaceAll(string& subject, const string& search, const string& replace) {
    size_t pos = 0;
    while((pos = subject.find(search, pos)) != string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){

        getchar();
        getline(cin,s);
        string s1,s2,s3,s4;
        replaceAll(s,"cheater","charming");
        replaceAll(s,"kala para na","khela pare");
        replaceAll(s,"appy nyc lagca","vaiya you are very handsome");
        replaceAll(s,"programmer","man with love and life");
       cout<<s<<'\n';
    }
    return 0;
}
