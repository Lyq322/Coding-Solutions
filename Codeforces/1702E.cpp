#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> adj;
		int a, b;
		for (int i = 0; i < n; i++) {
			adj.push_back({});
		}
		bool found = false;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			a--;
			b--;
			adj[b].push_back(a);
			adj[a].push_back(b);
			if (a == b || adj[a].size() > 2 || adj[b].size() > 2) found = true;
		}
		int visited[200000];
		for (int i = 0; i < n; i++) {
			visited[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			if (visited[i] == -1) {
				visited[i] = 0;
				stack<pair<int, int>> s;
				s.push({i, 0});
				while (!s.empty()) {
					if (found) break;
					int pos = s.top().first;
					int d = s.top().second;
					s.pop();
					for (int j = 0; j < adj[pos].size(); j++) {
						if (visited[adj[pos][j]] == -1) {
							visited[adj[pos][j]] = d + 1;
							s.push({adj[pos][j], d + 1});
						}
						else {
							if (d - visited[adj[pos][j]] % 2 == 0) {
								found = true;
								break;
							}
						}
					}
				}
				if (found) break;
			}
		}
		if (found) cout << "no\n";
		else cout << "yes\n";
	}
}

/*
Turn the problem into a graph — let the numbers on the dominos be nodes and let edges connect the two numbers on a domino
Three ways that you cannot split into 3 sets
1. Have a domino that have the same number twice - easily checked
2. A node that has more than 2 edges - also easily checked
3. An odd cycle - can be checked using dfs
*/