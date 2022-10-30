#include <bits/stdc++.h>
using namespace std;
 
struct segtree {
	int size;
	vector<int> minimums;
 
	void init(int N) {
		size = 1;
		while (size < N) size *= 2;
		minimums.assign(2 * size, 0);
	}
 
	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				minimums[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		minimums[x] = min(minimums[2 * x + 1], minimums[2 * x + 2]);
	}
 
	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}
 
	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			minimums[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		minimums[x] = min(minimums[2 * x + 1], minimums[2 * x + 2]);
	}
 
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
 
	int minimum(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 1000000000;
		if (lx >= l && rx <= r) return minimums[x]; 
		int m = (lx + rx) / 2;
		int m1 = minimum(l, r, 2 * x + 1, lx, m);
		int m2 = minimum(l, r, 2 * x + 2, m, rx);
		return min(m1, m2);
	}
 
	int minimum(int l, int r) {
		return minimum(l, r, 0, 0, size);
	}
};
 
int main() {
	int N, M;
	cin >> N >> M;
	segtree st;
	st.init(N);
	vector<int> a(N);
 
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	st.build(a);
	int b, c, d;
	for (int i = 0; i < M; i++) {
		cin >> b >> c >> d;
		if (b == 1) {
			st.set(c - 1, d);
		}
		else {
			cout << st.minimum(c - 1, d) << endl;
		}
	}
}
 