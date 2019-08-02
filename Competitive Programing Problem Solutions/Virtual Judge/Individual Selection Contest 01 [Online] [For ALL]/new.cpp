#include<bits/stdc++.h>
using namespace std;
int const MAX = 2e6 + 5;
int xval[MAX], head[MAX];
int n, cnt, ans;

struct EDGE
{
	int to, w;
	int next;
}e[MAX];

struct Tire
{
	int root, tot, next[MAX][2], end[MAX];

	inline int Newnode()
	{
		memset(next[tot], -1, sizeof(next[tot]));
		end[tot] = 0;
		return tot ++;
	}

	inline void Init()
	{
		tot = 0;
		root = Newnode();
	}

	inline void Insert(int x)
	{
		int p = root;
		for(int i = 31; i >= 0; i--)
		{
			int idx = ((1 << i) & x) ? 1 : 0;
			if(next[p][idx] == -1)
				next[p][idx] = Newnode();
			p = next[p][idx];
		}
		end[p] = x;
	}

	inline int Search(int x)
	{
		int p = root;
		for(int i = 31; i >= 0; i--)
		{
			int idx = ((1 << i) & x) ? 1 : 0;
			if(idx == 0)
				p = (next[p][1] != -1) ? next[p][1] : next[p][0];
			else
				p = (next[p][0] != -1) ? next[p][0] : next[p][1];
		}
		return x ^ end[p];
	}

}tr;

void Init()
{
	cnt = 0;
	memset(head, -1, sizeof(head));
	memset(xval, 0, sizeof(xval));
}

void Add(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt ++;
}

void DFS(int u, int fa)
{
	for(int i = head[u]; i != -1; i = e[i].next)
	{
		int v = e[i].to;
		if(v != fa)
		{
			xval[v] = xval[u] ^ e[i].w;
			DFS(v, u);
		}
	}
	return;
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		Init();
		int u, v, w, st;
		ans = 0;
		tr.Init();
		for(int i = 0; i < n - 1; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			Add(u, v, w);
			Add(v, u, w);
			st = u;
		}
		DFS(st, -1);
		for(int i = 0; i < n; i++)
		{
			tr.Insert(xval[i]);
			cout<<xval[i]<<endl;
			ans = max(ans, tr.Search(xval[i]));
		}
		printf("%d\n", ans);
	}
}
