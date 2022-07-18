#include <bits/stdc++.h>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int N, M;
	cin >> N >> M;
	int a, b;
	set<pair<int, int>> s;
	vector<vector<pii>> adj;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	long long ans = 1;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		if (s.find({a, b}) == s.end()) {
			s.insert({a, b});
		}
		else {
			s.erase(s.find({a, b}));
			adj[a].push_back({b, 2});
			adj[b].push_back({a, 2});
		}
	}
	for (auto it = s.begin(); it != s.end(); ++it) {
		adj[it -> first].push_back({it -> second, 1});
		adj[it -> second].push_back({it -> first, 1});
	}
	bool visited[100000] = {0};
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			stack<pii> s;
			s.push({i, i});
			int n = 0;
			int e = 0;
			while (!s.empty()) {
				int pos = s.top().first;
				int par = s.top().second;
				s.pop();
				n++;
				for (int j = 0; j < adj[pos].size(); j++) {
					e += adj[pos][j].second;
					if (!visited[adj[pos][j].first]) {
						visited[adj[pos][j].first] = true;
						s.push({adj[pos][j].first, pos});
					}
				}
			}
			if (e / 2 == n) {
				ans = (ans * 2) % 1000000007;
			}
			else {
				ans = (ans * n )% 1000000007;
			}
		}
	}
	cout << ans << endl;
}

/*
Casework
For each connected component: if there are N nodes and M edges
	Notice that if the graph is a tree (ie N = M + 1), then there will be N ways to “choose” a node that does not build a road
	If N == M, then there is a cycle in the graph. This means there will be 2 ways (clockwise and counterclockwise)
	If N > M + 1, then the graph is not connected
	N < M cannot happen as each cow builds only one road
*/