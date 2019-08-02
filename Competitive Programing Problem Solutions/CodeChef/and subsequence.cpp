#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 5;
const int Segment_Size = N * 4;

struct NODE {
	int l, r, id;
	void input(int _id) {
		scanf("%lld%lld", &l, &r);
		id = _id;
	}
}W;

vector < NODE > G[N];

int L[Segment_Size], R[Segment_Size], S[Segment_Size], lz[Segment_Size], ans[N];

#define lc (no << 1)
#define rc (no << 1 | 1)
#define getmid int mid = (L[no] + R[no]) >> 1

void up(int no) {
	S[no] = S[lc] + S[rc];
}

void pt(int no, int x) {
	S[no] += x * (R[no] - L[no] + 1);
	lz[no] += x;
}

void dn(int no) {
	if(L[no] == R[no] || !lz[no]) return;
	pt(lc, lz[no]);
	pt(rc, lz[no]);
	lz[no] = 0;
	up(no);
}

void build(int no, int l, int r) {
	lz[no] = S[no] = 0;
	L[no] = l, R[no] = r;
	if(l == r) return;
	getmid;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	up(no);
}

int query(int no, int l, int r) {
	dn(no);
	if(l == L[no] && R[no] == r) {
		return S[no];
	}
	getmid;
	int ans = 0;
	if(l > mid) ans = query(rc, l, r);
	else if(r <= mid) ans = query(lc, l, r);
	else ans = query(lc, l, mid) + query(rc, mid + 1, r);
	up(no);
	return ans;
}

void add(int no, int l, int r, int x) {
	dn(no);
	if(L[no] == l && R[no] == r) {
		pt(no, x);
		return;
	}
	getmid;
	if(l > mid) add(rc, l, r, x);
	else if(r <= mid) add(lc, l, r, x);
	else add(lc, l, mid, x), add(rc, mid + 1, r, x);
	up(no);
}

int n, q, l, r, A[N], stk[N], tot, s[N], t[N];

bool is(int x) {
	int now = (int) (sqrt(x) + 1e-3);
	return now * now == x;
}

void rebuild() {
	stk[0] = -1;
	int cnt = 0;
	for(int i = 1; i <= tot; ++ i) {
		if(stk[i] == stk[i - 1]) {
			t[cnt] = t[i];
			continue;
		}
		s[++ cnt] = s[i];
		t[cnt] = t[i];
		stk[cnt] = stk[i];
	}
	tot = cnt;
}

main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%lld%lld", &n, &q);
		build(1, 1, n);
		tot = 0;
		for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]), G[i].clear();
		for(int i = 1; i <= q; ++ i) {
			W.input(i);
			G[W.r].push_back(W);
		}
		for(int r = 1; r <= n; ++ r) {
			if(r == 1) {
				stk[++ tot] = A[r];
				s[tot] = t[tot] = 1;
				if(is(A[r])) add(1, 1, 1, 1);
			}
			else {
				stk[++ tot] = A[r];
				s[tot] = t[tot] = r;
				for(int i = 1; i <= tot; ++ i) stk[i] &= A[r];
				rebuild();
				for(int i = 1; i <= tot; ++ i) {
					if(is(stk[i])) add(1, s[i], t[i], 1);
				}
			}
			for(int i = 0; i < (int) G[r].size(); ++ i) {
				ans[G[r][i].id] = query(1, G[r][i].l, G[r][i].r);
			}
		}
		for(int i = 1; i <= q; ++ i) printf("%lld\n", ans[i]);
	}
}
