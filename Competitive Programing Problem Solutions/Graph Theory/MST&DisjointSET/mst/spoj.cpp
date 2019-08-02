#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
#define MOD 10000
#define MAX 10000
int N,M;
typedef class _x{
  public:
	int c,v;
	_x(int v1, int c1){
		c=c1; v=v1;
	}
}node;
struct comp{
	bool operator () (class _x a, class _x b){
		return a.c > b.c;
	}
};
vector <node> al[MAX+5];
int visited[MAX+5]={0};

int solve()
{
	long long res=0;
	priority_queue< class _x , vector<class _x> , comp > q;
	q.push(node(1,0));
	while(q.empty()!=true){
		class _x n = q.top();
		q.pop();
		if(visited[n.v])
			continue;
		//cout << n.v << ' ' << n.c << endl;
		visited[n.v]=1;
		res+=n.c;
		vector <node> & v = al[n.v];
		for(int i=0;i<v.size();i++)
			if( visited[v[i].v] == 0)
				q.push(node(v[i].v , v[i].c));
	}
	cout << res << endl;
}

int main(){
	int a,b,c;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> a >> b>>c;
		al[a].push_back(node(b,c));
		al[b].push_back(node(a,c));
	}
	solve();
	return 0;
}
