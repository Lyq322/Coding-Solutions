#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		int N, M;
		cin >> N >> M;
		int happy[100000];
		for (int i = 0; i < N; i++) {
			cin >> happy[i];
		}
		int a, b;
		int friends[100000] = {0};
		vector<pair<int, int>> p;
		int t = 0;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			a--;
			b--;
			p.push_back({a, b});
			friends[a]++;
			friends[b]++;
			t += 1;
		}
		if (t % 2 == 0) {
			cout << 0 << endl;
		}
		else {
			int ans = -1;
			for (int i = 0; i < N; i++) {
				if (friends[i] % 2 == 1) {
					if (ans == -1 || ans > happy[i]) {
						ans = happy[i];
					}
				}
			}
			for (int i = 0; i < M; i++) {
				if (friends[p[i].first] % 2 == 0 && friends[p[i].second] % 2 == 0) {
					if (ans == -1 || ans > happy[p[i].first] + happy[p[i].second]) {
						ans = happy[p[i].first] + happy[p[i].second];
					}
				}
			}
			cout << ans << endl;
		}
	}
}
