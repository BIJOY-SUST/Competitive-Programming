#include <iostream>
#include <cstdio>
#include<cstdlib>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int len=s.length();
    for(int i=0; i<len; i++){
        for(int j='a';j<='z';j++){
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
