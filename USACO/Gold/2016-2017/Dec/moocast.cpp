#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[1000];

struct dsu {
	vector<int> v;
	dsu(int n) { 
		v = vector<int>(n, -1); 
	}
	int get(int x) { 
		if (v[x] < 0) return x;
		else return v[x] = get(v[x]); 
	}
	bool connected(int a, int b) {
		return get(a) == get(b); 
	}
	int size(int x) { 
		return -v[get(x)]; 
	}
	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) return false;
		if (v[x] > v[y]) swap(x, y);
		v[x] += v[y]; 
		v[y] = x; 
		return true;
	}
};

bool cal(int i, int j, int d) {
	return (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second) <= d;
}

bool check(int dist) {
	dsu d(N);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (cal(i, j, dist) && !d.connected(i, j)) {
				d.unite(i, j);
			}
		}
	}
	return d.size(0) == N;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	int l = 0;
	int r = 1250000000;
	int m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (check(m) && (m == 0 || !check(m - 1))) {
			cout << m << endl;
			break;
		}
		else if (check(m)) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
}

/*
Binary search on answer
Use dsu to check if current radius works or not
*/