#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

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

bool comp(pair<int, pii> a, pair<int, pii> b) {
	return a.first > b.first;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, pii>> edges;
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		edges.push_back({c, {a, b}});
	}
	sort(edges.begin(), edges.end(), comp);
	pair<int, pii> queries[100000];
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		b--;
		queries[i] = {a, {b, i}};
	}
	sort(queries, queries + M, comp);
	dsu d(N);
	int ans[100000];
	int j = 0;
	for (int i = 0; i < M; i++) {
		while (j < N - 1) {
			if (edges[j].first >= queries[i].first) {
				d.unite(edges[j].second.first, edges[j].second.second);
			}
			else break;
			j++;
		}
		ans[queries[i].second.second] = d.size(queries[i].second.first) - 1;
	}
	for (int i = 0; i < M; i++) {
		cout << ans[i] << endl;
	}
}

// Simple DSU, uniting nodes by their relevance and sorting the queries in order to find everything in one pass