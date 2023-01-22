#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<pii> edges;
	char c;
	int a, b;
	bool delete_edge[200000] = {0};
	bool closed[100000] = {0};
	pii queries[200000];
	for (int i = 0; i < Q; i++) {
		cin >> c;
		if (c == 'A') {
			cin >> a >> b;
			a--;
			b--;
			edges.push_back({a, b});
			queries[i] = {-1, -1};
		}
		else if (c == 'R') {
			cin >> a;
			a--;
			delete_edge[a] = true;
			queries[i] = {0, a};
		}
		else {
			cin >> a;
			a--;
			closed[a] = true;
			queries[i] = {1, a};
		}
	}
	vector<vector<int>> adj;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	for (int i = 0; i < edges.size(); i++) {
		if (!delete_edge[i]) {
			adj[edges[i].first].push_back(edges[i].second);
			adj[edges[i].second].push_back(edges[i].first);
		}
	}
	int ans[100000];
	for (int i = 0; i < N; i++) {
		if (closed[i]) {
			ans[i] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (!closed[i]) {
			ans[i] = Q;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (int j = 0; j < adj[cur].size(); j++) {
					if (ans[adj[cur][j]] == -1) {
						ans[adj[cur][j]] = Q;
						q.push(adj[cur][j]);
					}
				}
			}
		}
	}
	for (int i = Q - 1; i > -1; i--) {
		if (queries[i].first == 0) {
			a = edges[queries[i].second].first;
			b = edges[queries[i].second].second;
			queue<int> q;
			if (ans[a] == -1 && ans[b] != -1) {
				q.push(a);
				ans[a] = i;
			}
			else if (ans[b] == -1 && ans[a] != -1) {
				q.push(b);
				ans[b] = i;
			}
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (int j = 0; j < adj[cur].size(); j++) {
					if (ans[adj[cur][j]] == -1) {
						ans[adj[cur][j]] = i;
						q.push(adj[cur][j]);
					}
				}
			}
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		else if (queries[i].first == 1) {
			a = queries[i].second;
			if (ans[a] == -1) {
				queue<int> q;
				q.push(a);
				ans[a] = i;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					for (int j = 0; j < adj[cur].size(); j++) {
						if (ans[adj[cur][j]] == -1) {
							ans[adj[cur][j]] = i;
							q.push(adj[cur][j]);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
}
