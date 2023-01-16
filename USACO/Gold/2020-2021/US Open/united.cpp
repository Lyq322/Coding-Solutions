#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
The question is the same as queries on distinct values in a range (end at current i, start at previous index j with same breed as i, exclusive)
This can be solved by maintaining a segment tree of the last index of any breed
*/

struct segtree {
	int size;
	vector<ll> sums;

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		sums.assign(2 * size, 0);
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
	int N;
	cin >> N;
	int arr[200000];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	int previous[200000];
	int track[200000];
	for (int i = 0; i < N; i++) {
		track[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		previous[i] = track[arr[i]];
		track[arr[i]] = i;
	}
	ll ans = 0;
	segtree st;
	st.init(N);
	for (int i = 0; i < N; i++) {
		ll count = st.sum(previous[i] + 1, i);
		if (previous[i] == -1) {
			st.set(i, 1);
		}
		else {
			st.set(i, 1);
			st.set(previous[i], 0);
		}
		ans += count;
	}
	cout << ans << endl;
}
