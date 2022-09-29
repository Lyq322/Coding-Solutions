#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;

ifstream fin;
ofstream fout;

struct segtree {
	int size;
	vector<ll> sums;

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

int main() {
	fin.open("circlecross.in");
	fout.open("circlecross.out");
	int N;
	fin >> N;
	vector<int> v(2 * N);
	for (int i = 0; i < 2 * N; i++) {
		fin >> v[i];
	}

	segtree st;
	st.init(2 * N);
	int visited[50001];
	for (int i = 0; i <= N; i++) {
		visited[i] = -1;
	}
	ll ans = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (visited[v[i]] == -1) {
			visited[v[i]] = i;
			st.set(i, 1);
		}
		else {
			ans += st.sum(visited[v[i]] + 1, i);
			st.set(visited[v[i]], 0);
		}
	}
	fout << ans << endl;
}
