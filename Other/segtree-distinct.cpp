#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
	int size;
	vector<ll> sums;

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		sums.assign(2 * size, 0LL);
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
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return sums[x];

		int m = (lx + rx) / 2;
		ll s1 = sum(l, r, 2 * x + 1, lx, m);
		ll s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}

	ll sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.first.second < b.first.second;
}

int main() {
	int N, M;
	cin >> N >> M;
	segtree st;
	st.init(N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	map<int, int> m;
	vector<pair<pair<int, int>, int>> p(M);
	for (int i = 0; i < M; i++) {
		cin >> p[i].first.first >> p[i].first.second;
		p[i].second = i;
	}
	sort(p.begin(), p.end(), comp);
	int index = 0;
	int ans[200000];
	for (int i = 0; i < N; i++) {
		if (index >= M) break;
		if (m.find(v[i]) != m.end()) {
			st.set(m[v[i]], 0);
			st.set(i, 1);
			m[v[i]] = i;
		}
		else {
			m[v[i]] = i;
			st.set(i, 1);
		}
		while (index < M) {
			if (p[index].first.second - 1 > i) {
				break;
			}
			else {
				ans[p[index].second] = st.sum(p[index].first.first - 1, p[index].first.second);
				index++;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cout << ans[i] << endl;
	}
}
