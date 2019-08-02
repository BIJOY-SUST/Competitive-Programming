#include<bits/stdc++.h>
using namespace std;

void by_value(int a){
	a+=10;
}

void by_ref(int *a){
	(*a)+=10;
}

int by_ref2(int &a){
	a+=10;
}

int main(){
	int x=40;
	cout<<by_value(x)<<endl;
	//x==40
	cout<<by_ref(&x)<<endl;
	//x==50
	cout<<by_ref2(x)<<endl;
	//x==60
	return 0;
}
