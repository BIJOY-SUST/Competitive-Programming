#include<cstdio>
#include<iostream>
#include<algorithm>


using namespace std;

int main(){
    long long int n,i,ara[100000],c;
    cin>>n;
	for(i=0;i<n;i++){
        cin>>ara[i];
	}
	sort(ara, ara+n);
	c=1;
	for(i=0;i<n;i++){
        if(c<=ara[i]){
            c++;
        }
	}
	cout<<c<<endl;
    return 0;
}
