#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

int main()
{
    int count=0;
    string num;
    cin >> num;
    int a = atoi(num.c_str());
    cout<<a<<endl;
    int len=num.length();
    for(int i=0; i<len; i++){
        if(num[i]=='4' || num[i]=='7')
            count++;
    }
    if(count==len)
        cout<<"YES"<<endl;
    else if(a%47==0)
        cout<<"YES"<<endl;
    else if (a%4==0 || a%7==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    return 0;
}
