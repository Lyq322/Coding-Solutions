#include <bits/stdc++.h>
using namespace std;

int N, M;

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

int main() {
	cin >> N >> M;
	vector<vector<int>> adj;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> order;
	for (int i = 0; i < N; i++) {
		cin >> a;
		a--;
		order.push_back(a);
	}
	reverse(order.begin(), order.end());
	dsu d(N);
	bool visited[200000] = {0};
	int components = 0;
	bool ans[200000];
	for (int i = 0; i < N; i++) {
		components++;
		visited[order[i]] = true;
		for (int j = 0; j < adj[order[i]].size(); j++) {
			if (!d.connected(order[i], adj[order[i]][j]) && visited[adj[order[i]][j]]) {
				d.unite(order[i], adj[order[i]][j]);
				components--;
			}
		}
		if (components == 1) {
			ans[i] = true;
		}
		else ans[i] = false;
	}
	for (int i = N - 1; i > -1; i--) {
		if (ans[i]) cout << "YES\n";
		else cout << "NO\n";
	}
	cout << endl;
}
