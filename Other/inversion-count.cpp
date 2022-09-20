#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
	int size;
	vector<int> sums;

	void init(int N) {
		size = 1;
		while (size < N) size *= 2;
		sums.assign(2 * size, 0);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				sums[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	
	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			sums[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	ll sum(int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return 0;
		if (rx <= r && lx >= l) return sums[x];
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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> a(N);
		vector<int> b;
		segtree st;
		st.init(N);
		map<int, int> m;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
			b.push_back(a[i]);
		}
		sort(b.begin(), b.end());
		for (int i = 0; i < N; i++) {
			m[b[i]] = i;
		}
		for (int i = 0; i < N; i++) {
			a[i] = m[a[i]];
		}
		ll ans = 0;
		for (int i = 0; i < N; i++) {
			ans += st.sum(a[i] + 1, N);
			st.set(a[i], 1);
		}
		cout << ans << endl;
	}
}
