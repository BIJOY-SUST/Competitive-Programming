#include <cstdio>
#include<iostream>
#include <algorithm>

using namespace std;

int main(){
	int k,n;

	scanf("%d %d",&k,&n);

	int sum = 0,ara[1000];

	for(int i = 0;i < n;++i){
		scanf("%d",&ara[i]);
		sum += ara[i];
		sum = max(0,sum - k);
	}

	printf("%d\n",sum);

	return 0;
}
