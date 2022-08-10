#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int ccw(pii a, pii b, pii c) {
	ll area = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
	if (area > 0) {
		return 1;
	}
	else if (area < 0) {
		return -1;
	}
	else return 0;
}

bool check(pii p1, pii p2, pii q1, pii q2) {
    int r1 = ccw(p1, p2, q1) * ccw(p1, p2, q2);
    int r2 = ccw(q1, q2, p1) * ccw(q1, q2, p2);
	return (r1 <= 0 && r2 <= 0);
}
  

int main() {
	int N, M;
	cin >> N >> M;
	pair<pii, pii> fences[1000];
	map<pii, vector<int>> m;
	for (int i = 0; i < N; i++) {
		cin >> fences[i].first.first >> fences[i].first.second >> fences[i].second.first >> fences[i].second.second;
		if (m.find(fences[i].first) != m.end()) {
			m[fences[i].first].push_back(i);
		}
		else {
			m[fences[i].first] = {};
			m[fences[i].first].push_back(i);
		}
		if (m.find(fences[i].second) != m.end()) {
			m[fences[i].second].push_back(i);
		}
		else {
			m[fences[i].second] = {};
			m[fences[i].second].push_back(i);
		}
	}
	vector<vector<int>> adj;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		adj[it -> second[0]].push_back(it -> second[1]);
		adj[it -> second[1]].push_back(it -> second[0]);
	}
	int polygon[1000];
	for (int i = 0; i < N; i++) {
		polygon[i] = -1;
	}
	int index = 0;
	for (int i = 0; i < N; i++) {
		if (polygon[i] == -1) {
			int cur = i;
			while (true) {
				polygon[cur] = index;
				if (polygon[adj[cur][0]] != -1 && polygon[adj[cur][1]] != -1) {
					break;
				}
				else if (polygon[adj[cur][0]] == -1) {
					cur = adj[cur][0];
				}
				else {
					cur = adj[cur][1];
				}
			}
			index++;
		}
	}
	pii cows[1000];
	for (int i = 0; i < M; i++) {
		cin >> cows[i].first >> cows[i].second;
	}
	int intersection[1000][1000] = {{0}};
	for (int i = 0; i < M; i++) {
		pii p1 = cows[i];
		pii p2 = {cows[i].first + 1000001, cows[i].second + 1};
		for (int j = 0; j < N; j++) {
			pii q1 = fences[j].first;
			pii q2 = fences[j].second;
			if (check(p1, p2, q1, q2)) {
				intersection[i][polygon[j]]++;
			}
		}
	}
	map<vector<int>, int> m2;
	for (int i = 0; i < M; i++) {
		vector<int> v;
		for (int j = 0; j < N; j++) {
			if (intersection[i][j] % 2 == 1) {
				v.push_back(j);
			}
		}
		if (m2.find(v) == m2.end()) {
			m2[v] = 1;
		}
		else {
			m2[v]++;
		}
	}
	int ans = 0;
	for (auto it = m2.begin(); it != m2.end(); it++) {
		ans = max(ans, it -> second);
	}
	cout << ans << endl;
}
