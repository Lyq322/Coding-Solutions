#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;

ifstream fin;
ofstream fout;

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

	void increment(int i, int x, int lx, int rx) {
		if (rx - lx == 1) {
			sums[x]++;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			increment(i, 2 * x + 1, lx, m);
		}
		else {
			increment(i, 2 * x + 2, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void increment(int i) {
		increment(i, 0, 0, size);
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
	fin.open("bphoto.in");
	fout.open("bphoto.out");
	int N;
	fin >> N;
	int arr[100000];
	vector<int> sorted;
	for (int i = 0; i < N; i++) {
		fin >> arr[i];
		sorted.push_back(arr[i]);
	}
	sort(sorted.begin(), sorted.end());
	map<int, int> compress;
	int index = 0;
	for (int i = 0; i < N; i++) {
		if (compress.find(sorted[i]) == compress.end()) {
			compress[sorted[i]] = index;
			index++;
		}
	}
	for (int i = 0; i < N; i++) {
		arr[i] = compress[arr[i]];
	}
	segtree st;
	st.init(index);
	int left[100000];
	int right[100000];
	for (int i = 0; i < N; i++) {
		left[i] = st.sum(arr[i] + 1, index);
		st.increment(arr[i]);
	}
	st.init(index);
	for (int i = N - 1; i > -1; i--) {
		right[i] = st.sum(arr[i] + 1, index);
		st.increment(arr[i]);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (left[i] > 2 * right[i] || right[i] > 2 * left[i]) {
			ans++;
		}
	}
	fout << ans << endl;
}
