#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct segtree {
	int size;
	vector<ll> sums;
 
	void init(int N) {
		size = 1;
		while (size < N) size *= 2;
		sums.assign(2 * size, 0LL);
	}
 
	void increase(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			sums[x] += v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			increase(i, v, 2 * x + 1, lx, m);
		}
		else {
			increase(i, v, 2 * x + 2, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
 
	void increase(int i, int v) {
		increase(i, v, 0, 0, size);
	}
 
	ll sum(int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return 0;
		else if (lx >= l && rx <= r) return sums[x];
		int m = (lx + rx) / 2;
		ll s1 = sum(l, r, 2 * x + 1, lx, m);
		ll s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}
 
	ll sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};
 
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	segtree st;
	st.init(N + 1);
	int q;
	int b, c, d;
	for (int i = 0; i < M; i++) {
		cin >> q;
		if (q == 1) {
			cin >> b >> c >> d;
			st.increase(b - 1, d);
			st.increase(c, -d);
		}
		else {
			cin >> b;
			cout << st.sum(0, b) + a[b - 1] << endl;
		}
	}
}