#include <bits/stdc++.h>

using namespace std;

int T, N, M;

int main() {
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> N >> M;
		vector<vector<int>> v;
		vector<int> need_swap;
		int q;
		bool w = true;
		for (int i = 0; i < N; i++) {
			v.push_back({});
			for (int j = 0; j < M; j++) {
				cin >> q;
				v[i].push_back(q);
			}
		}
		for (int i = 0; i < N; i++) {
			vector<int> v_sorted;
			for (int j = 0; j < M; j++) {
				v_sorted.push_back(v[i][j]);
			}
			if (!w) continue;
			sort(v_sorted.begin(), v_sorted.end());
			vector<int> bad;
			for (int j = 0; j < M; j++) {
				if (v_sorted[j] != v[i][j]) {
					bad.push_back(j);
				}
			}
			if (bad.size() == 2) {
				for (int j = 0; j < N; j++) {
					int temp = v[j][bad[0]];
					v[j][bad[0]] = v[j][bad[1]];
					v[j][bad[1]] = temp;
				}
				bool b = true;
				for (int k = 0; k < N; k++) {
					for (int j = 0; j < M - 1; j++) {
						if (v[k][j] > v[k][j + 1]) {
							b = false;
							break;
						}
					}
				}
				if (!b) {
					cout << -1 << endl;
				}
				else {
					cout << bad[0] + 1 << ' ' << bad[1] + 1 << endl;
				}
				w = false;
			}
			else if (bad.size() >= 3) {
				cout << -1 << endl;
				w = false;
			}
		}
		if (!w) continue;
		cout << 1 << ' ' << 1 << endl;
	}
}
