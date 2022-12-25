#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> order[50000];
vector<int> topo;

struct Node {
	int pos;
};

bool operator<(Node a, Node b) {
	return a.pos > b.pos;
}

bool check(int x) {
	topo.clear();
	vector<vector<int>> adj;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	int in_deg[100000] = {0};
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < order[i].size() - 1; j++) {
			adj[order[i][j]].push_back(order[i][j + 1]);
			in_deg[order[i][j + 1]]++;
		}
	}
	priority_queue<Node> q;
	for (int i = 0; i < N; i++) {
		if (in_deg[i] == 0) {
			q.push({i});
		}
	}
	while (!q.empty()) {
		int p = q.top().pos;
		q.pop();
		topo.push_back(p);
		for (int i = 0; i < adj[p].size(); i++) {
			in_deg[adj[p][i]]--;
			if (in_deg[adj[p][i]] == 0) {
				q.push({adj[p][i]});
			}
		}
	}
	if (topo.size() == N) return true;
	else return false;
}

int main() {
	ifstream fin("milkorder.in");
	ofstream fout("milkorder.out");
	fin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		fin >> a;
		for (int j = 0; j < a; j++) {
			fin >> b;
			order[i].push_back(b - 1);
		}
	}
	int l = 1;
	int r = M;
	int m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (check(m) && (m == M || !check(m + 1))) {
			check(m);
			for (int i = 0; i < topo.size() - 1; i++) {
				fout << topo[i] + 1 << ' ';
			}
			fout << topo[N - 1] + 1 << endl;
			break;
		}
		else if (check(m)) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
}
