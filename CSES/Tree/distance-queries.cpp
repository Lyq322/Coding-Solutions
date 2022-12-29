#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> nodes;
vector<pair<int, int>> depths;

void dfs(int pos, int depth, int par) {
	nodes.push_back(pos);
	depths.push_back({depth, pos});
	for (int i = 0; i < adj[pos].size(); i++) {
		int next = adj[pos][i];
		if (next == par) continue;
		dfs(next, depth + 1, pos);
		nodes.push_back(pos);
		depths.push_back({depth, pos});
	}
}

struct segtree {
	int size;
	vector<pair<int, int>> minimums;

	void init(int N) {
		size = 1;
		while (size < N) size *= 2;
		for (int i = 0; i < 2 * size; i++) {
			minimums.push_back({0, 0});
		}
	}

	void build(vector<pair<int, int>> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				minimums[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		if (minimums[2 * x + 1].first < minimums[2 * x + 2].first) {
			minimums[x] = minimums[2 * x + 1];
		}
		else {
			minimums[x] = minimums[2 * x + 2];
		}
	}

	void build(vector<pair<int, int>> &a) {
		build(a, 0, 0, size);
	}

	pair<int, int> minimum(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return {1000000000, 0};
		if (lx >= l && rx <= r) return minimums[x]; 
		int m = (lx + rx) / 2;
		pair<int, int> m1 = minimum(l, r, 2 * x + 1, lx, m);
		pair<int, int> m2 = minimum(l, r, 2 * x + 2, m, rx);
		if (m1.first < m2.first) {
			return m1;
		}
		else {
			return m2;
		}
	}

	pair<int, int> minimum(int l, int r) {
		return minimum(l, r, 0, 0, size);
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, 1, -1);
	segtree st;
	st.init(2 * N - 1);
	st.build(depths);
	int index[400000];
	int d[200000];
	for (int i = 0; i < 2 * N - 1; i++) {
		index[depths[i].second] = i;
		d[depths[i].second] = depths[i].first;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		int l = st.minimum(min(index[a], index[b]), max(index[a], index[b]) + 1).second;
		cout << d[a] + d[b] - 2 * d[l] << endl;
	}
}
