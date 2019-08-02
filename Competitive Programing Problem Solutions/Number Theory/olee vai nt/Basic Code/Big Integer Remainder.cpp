#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    long long int d,reminder=0;
    printf("Enter Dividend And Divisor\n");
//    scanf("%s",&s);
//    scanf("%lld",&d);
    cin>>s>>d;
    for(int i=0;i<s.length();i++){
        reminder=((reminder*10)+(s[i]-'0'))%d;
    }
    printf("Reminder is = %lld\n",reminder);
    return 0;
}
