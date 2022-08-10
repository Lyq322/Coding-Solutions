#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int par[200000];
int N, M;
vector<vector<int>> adj;
int sz[200000];
queue<int> q;

int get(int a) {
	if (par[a] == a) {
		return a;
	}
	return par[a] = get(par[a]);
}

void unite(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b) {
		return;
	}
	if (sz[a] < sz[b]) {
		swap(a, b);
	}
	par[b] = a;
	sz[a] += sz[b];
	for (int i = 0; i < adj[b].size(); i++) {
		adj[a].push_back(adj[b][i]);
	}
	adj[b].clear();
	if (adj[a].size() > 1) {
		q.push(a);
	}
}

int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
	}
	for (int i = 0; i < N; i++) {
		if (adj[i].size() > 1) {
			q.push(i);
		}
		par[i] = i;
		sz[i] = 1;
	}
	while (!q.empty()) {
		int p = q.front();
		if (adj[p].size() <= 1) {
			q.pop();
			continue;
		}
		int v = adj[p].back();
		adj[p].pop_back();
		if (get(v) == get(adj[p].back())) {
			continue;
		}
		unite(v, adj[p].back());
	}
	map<int, int> m;
	int index = 1;
	for (int i = 0; i < N; i++) {
		if (m.find(get(i)) == m.end()) {
			m[get(i)] = index;
			cout << index << endl;
			index++;
		}
		else cout << m[get(i)] << endl;
	}
}

/*
Very nice problem :), even though I couldn’t solve it
Create a dsu-ish structure – connected components mean the nodes have the same color
We want to merge the children of all nodes that have more than 1 children (eg. if node x have children a and b, merge a and b)
	We also need to merge the adj lists of the children
	Brute force would mean O(N), but using merging by size we can reduce that to log N
*/