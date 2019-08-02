#include<bits/stdc++.h>
#define mx 1000001
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int len=max(s1.length(),s2.length());
    int c=0;
    int a=0,b=0;
    int s3[mx],s4[mx];
    for(int i=s1.length()-1;i>=0;i--) s3[a++]=s1[i]-'0';
    for(int i=s2.length()-1;i>=0;i--) s4[b++]=s2[i]-'0';
    for(int i=a;i<len;i++) s3[i]=0;
    for(int i=b;i<len;i++) s4[i]=0;
    for(int i=len-1;i>=0;i--){
        if(s3[i]>s4[i]){
            c=1;
            break;
        }
        else if(s3[i]<s4[i]){
            c=2;
            break;
        }
    }
    if(c==1) printf(">\n");
    else if(c==2) printf("<\n");
    else if(c==0) printf("=\n");
    return 0;
}



//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    string s1,s2;
//    cin>>s1>>s2;
//    int c=0;
//    for(int i=0;i<s1.length();i++){
//        if(s1[i]=='0'){
//            s1.erase(s1.begin());
//            i--;
//        }
//        else break;
//    }
//    for(int i=0;i<s2.length();i++){
//        if(s2[i]=='0'){
//            s2.erase(s2.begin());
//            i--;
//        }
//        else break;
//    }
////    cout<<s1<<'\n';
////    cout<<s2<<'\n';
//    if(s1.length()==s2.length()){
//        for(int i=0;i<s1.length();i++){
//            if(s1[i]>s2[i]){
//                c=1;
//                break;
//            }
//            else if(s1[i]<s2[i]){
//                c=2;
//                break;
//            }
//        }
//        if(c==1) printf(">\n");
//        else if(c==2) printf("<\n");
//        else if(c==0) printf("=\n");
//    }
//    else{
//        if(s1.length()>s2.length()) printf(">\n");
//        else printf("<\n");
//    }
//    return 0;
//}
//8631749422082281871941140403034638286979613893271246118706788645620907151504874585597378422393911017
//1460175633701201615285047975806206470993708143873675499262156511814213451040881275819636625899967479
