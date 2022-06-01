#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, K;

int main() {
	cin >> N >> K;
	set<int> points;
	vector<int> dist;
	int a;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a % 12 != 0 && points.find((a + 11) / 12) == points.end()) {
			ans++;
		}
		points.insert((a + 11) / 12);
	}
	for (auto it = points.begin(); next(it) != points.end(); ++it) {
		dist.push_back(*next(it) - *it);
	}
	dist.push_back(*points.begin());
	sort(dist.begin(), dist.end());
	for (int i = 0; i < (int) points.size() - K + 1 && i < dist.size(); i++) {
		ans += dist[i] - 1;
	}
	cout << ans * 12 << endl;
}
