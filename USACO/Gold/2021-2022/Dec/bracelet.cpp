#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		bool found = false;
		int N, M;
		cin >> N >> M;
		int a, b;
		vector<vector<int>> adj;
		for (int i = 0; i < M; i++) {
			cin >> a;
			adj.push_back({});
			for (int j = 0; j < a; j++) {
				cin >> b;
				adj[i].push_back(b);
			}
		}
		for (int i = 0; i < M; i++) {
			map<int, int> m;
			for (int j = 0; j < adj[i].size(); j++) {
				if (m.find(adj[i][j]) == m.end()) {
					m[adj[i][j]] = j;
				}
				else {
					int count[51] = {0};
					for (int k = m[adj[i][j]] + 1; k < j; k++) {
						count[adj[i][k]]++;
					}
					for (int k = 0; k < 51; k++) {
						if (count[k] % 2 == 1) {
							cout << "NO" << endl;
							found = true;
							break;
						}
					}
				}
				if (found) break;
			}
			if (found) break;
		}
		if (found) continue;
		int first[51];
		int last[51];
		for (int i = 0; i < 51; i++) {
			first[i] = -1;
			last[i] = -1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				if (first[adj[i][j]] == -1) {
					first[adj[i][j]] = i;
				}
				last[adj[i][j]] = i;
			}
		}
		for (int i = 1; i < 51; i++) {
			if (first[i] != last[i]) {
				for (int j = first[i] + 1; j < last[i]; j++) {
					bool f = false;
					for (int k = 0; k < adj[j].size(); k++) {
						if (adj[j][k] == i) {
							f = true;
							break;
						}
					}
					if (!f) {
						cout << "NO" << endl;
						found = true;
						break;
					}
				}
				if (found) break;
			}
		}
		if (found) continue;
		for (int i = 0; i < M - 1; i++) {
			if (adj[i].size() == 0 || adj[i + 1].size() == 0) continue;
			vector<vector<pair<int, int>>> pairs;
			for (int j = 0; j < 51; j++) {
				pairs.push_back({});
			}
			for (int j = 0; j < adj[i].size(); j++) {
				pairs[adj[i][j]].push_back({j, 0});
			}
			for (int j = 0; j < adj[i + 1].size(); j++) {
				pairs[adj[i + 1][j]].push_back({j, 1});
			}
			vector<pair<int, int>> cross;
			for (int j = 1; j < 51; j++) {
				if (pairs[j].size() == 4) {
					cross.push_back({pairs[j][0].first, pairs[j][2].first});
					cross.push_back({pairs[j][1].first, pairs[j][3].first});
				}
				else if (pairs[j].size() == 2) {
					if (pairs[j][0].second == 0) {
						for (int k = pairs[j][0].first + 1; k < pairs[j][1].first; k++) {
							if (pairs[adj[i][k]].size() == 4) {
								cout << "NO" << endl;
								found = true;
								break;
							}
						}
					}
					else {
						for (int k = pairs[j][0].first + 1; k < pairs[j][1].first; k++) {
							if (pairs[adj[i + 1][k]].size() == 4) {
								cout << "NO" << endl;
								found = true;
								break;
							}
						}
					}
				}
				if (found) break;
			}
			if (found) break;
			for (int j = 0; j < cross.size(); j++) {
				for (int k = j + 1; k < cross.size(); k++) {
					if ((cross[j].first < cross[k].first && cross[j].second > cross[k].second) || (cross[j].first > cross[k].first && cross[j].second < cross[k].second)) {
						cout << "NO" << endl;
						found = true;
						break;
					}
				}
				if (found) break;
			}
			if (found) break;
		}
		if (found) continue;
		cout << "YES" << endl;
	}
}
