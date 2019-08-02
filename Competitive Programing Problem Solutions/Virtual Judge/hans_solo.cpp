#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector< pair<int,int > >v;
bool k[1001] = {};

int main(){
	int n,x,y,x1,y1;
	cin >> n >> x >> y;
	for(int i = 0 ; i < n ; i++){
		cin >> x1 >> y1;
		v.push_back(make_pair(x1,y1));
	}
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		int a = v[i].first,b = v[i].second;
		if(!k[i]){
			ans++;
		}
		k[i] = true;
		for(int j = i + 1 ; j < n ;j++){
			int x2= v[j].first,y2 = v[j].second;
			if(!k[j] && (x2 - x) * (b - y) == (a - x) * (y2 - y)){
				k[j] = true;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
