#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,c=0;
	char ch;
	cin>>k;
	string s;
	cin>>s;
	int l=s.size();
	sort(s.begin(),s.begin()+s.size());
	for(int i=0;i<s.size();i++){
	    if(i%k==0){
	       ch=s[i];
	    }
	    if(s[i]==ch){
	        c++;
//	        cout<<c<<endl;
	    }
	}
//	cout<<c<<endl;
	if(l==c && c%k==0){
	    for(int i=0;i<k;i++){
	        for(int h=0;h<s.size();h+=k){
	            cout<<s[h];
	        }
	    }
	}
	else{
	    cout<<"-1";
	}
    return 0;
}
