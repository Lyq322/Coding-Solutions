#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> v;
vector<vector<int>> adj;
bool visited[100000] = {0};
vector<int> topo_v;

void topo(int node) {
	for (int k = 0; k < adj[node].size(); k++) {
		int next = adj[node][adj[node].size() - k - 1];
		if (!visited[next]) {
			visited[next] = true;
			topo(next);
		}
	}
	topo_v.push_back(node);
}

struct Cow {
	int o;
	int pos;
};

bool operator<(Cow a, Cow b) {
	return a.o > b.o;
}

bool check(int X, bool b) {
	adj.clear();
	for (int i = 0; i < N; i++) {
		adj.push_back({});
		visited[i] = false;
	}
	bool start[100000] = {0};
	for (int i = 0; i < X; i++) {
		for (int j = 1; j < v[i].size(); j++) {
			adj[v[i][j - 1]].push_back(v[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			start[adj[i][j]] = true;
		}
		sort(adj[i].begin(), adj[i].end());
	}
	int index = 0;
	int ind[100000] = {0};
	vector<vector<int>> topos;
	int topos_index = 0;
	for (int i = 0; i < N; i++) {
		if (!start[i]) {
			topo_v.clear();
			visited[i] = true;
			topo(i);
			for (int j = 0; j < topo_v.size(); j++) {
				ind[topo_v[topo_v.size() - j - 1]] = index;
				index++;
			}
			if (b) {
				topos.push_back({});
				for (int j = 0; j < topo_v.size(); j++) {
					topos[topos_index].push_back(topo_v[topo_v.size() - j - 1]);
				}
				topos_index++;
			}
		}
	}
	if (b) {
		vector<int> ans;
		priority_queue<Cow> q;
		int indices[100000] = {0};
		for (int i = 0; i < topos_index; i++) {
			q.push({topos[i][0], i});
		}
		while (!q.empty()) {
			ans.push_back(q.top().o);
			int pos = q.top().pos;
			q.pop();
			if (topos[pos].size() - 1 > indices[pos]) {
				indices[pos]++;
				q.push({topos[pos][indices[pos]], pos});
			}
		}
		for (int i = 0; i < N; i++) {
			cout << ans[i] + 1 << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (ind[adj[i][j]] <= ind[i]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> N >> M;
	int a, b;
	int prev;
	for (int i = 0; i < M; i++) {
		cin >> a;
		v.push_back({});
		for (int j = 0; j < a; j++) {
			cin >> b;
			v[i].push_back(b - 1);
		}
	}
	int l = 1;
	int r = M;
	int m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (check(m, false) && (m == M || !check(m + 1, false))) {
			break;
		}
		else if (check(m, false)) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	check(m, true);
}

/*
Code doesn't work...
If X = k does not work, then X = k + 1 will not work either
⇒ Binary search on X!
Use topological sort to check if X = k works
	DFS or BFS
	I don't think if DFS works if the problem requires a lexicographically smaller answer?
	After the topo sort finds n connected components, use priority queue to determine the lexicographically smallest answer
*/