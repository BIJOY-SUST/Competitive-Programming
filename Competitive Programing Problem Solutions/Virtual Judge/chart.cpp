#include <iostream>
#include <cstdio>
#include<cstdlib>
#include <string>

using namespace std;

int main()
{
    string ques="hello";
    string s;
    cin>>s;
    int len=s.length();
    int count = 0;
    for(int i=0,j=0; i<len; i++){
        if(s[i]==ques[j]){
            j++;
            count++;
        }
    }
    if(count==5)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
