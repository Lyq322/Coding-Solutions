#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
First thing to do is to try to figure out the number of moos for only a single bubble sort
Imagine there is a partition in the array. Notice that a single pass of a single bubble sort will only bring at most one element across the partition (from left to right)
If there are more than one elements that need to cross over from left to right of the partition, then there must be multiple passes
We can apply this to double bubble sorts as well
The number of passes needed for each partition is the number of elements that are left of the partition in the original array, but right of the partition in the sorted array
	This is different from single bubble sort since an element left of the partition can stay there even if there is an element less than it to the right of the partition
	We can use segment tree/BIT to calculate this
We want to find the maximum of above for all partitions
*/

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
	int N;
	cin >> N;
	int arr[100000];
	pair<int, int> sorted_arr[100000];
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sorted_arr[i] = {arr[i], i};
	}
	sort(sorted_arr, sorted_arr + N);
	for (int i = N - 1; i > -1; i--) {
		m[sorted_arr[i].first] = i;
	}
	segtree st;
	st.init(N);
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		st.set(m[arr[i]], 1);
		m[arr[i]]++;
		ans = max(ans, i + 1 - st.sum(0, i + 1));
	}
	cout << max(ans, (ll) 1);
}
