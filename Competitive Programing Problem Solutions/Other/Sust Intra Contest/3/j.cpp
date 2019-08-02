#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    char s;
    cin>>t;
    while(t--){
		scanf("%d",&n);
		getchar();
		long long int ans,c=0;
		for(int i=0;i<n;i++){
			scanf("%c",&s);

			if(s == '1')
				c++;
		}
		ans=c*(c+1)/2;
		printf("%lld\n",ans);
    }
    return 0;
}

