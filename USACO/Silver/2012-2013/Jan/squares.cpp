#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int N, M;
	cin >> N >> M;
	int a, b;
	set<pii> x;
	set<pii> y;
	vector<pii> v;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	bool found = false;
	bool two = true;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		while (!x.empty()) {
			if (x.begin() -> first + M <= v[i].first) {
				y.erase(y.find({x.begin() -> second, x.begin() -> first}));
				x.erase(x.begin());
			}
			else break;
		}
		x.insert(v[i]);
		y.insert({v[i].second, v[i].first});
		auto it = y.find({v[i].second, v[i].first});
		int x1 = it -> second;
		int y1 = it -> first;
		if (y.size() > 1) {
			if (it != y.begin()) {
				int x2 = prev(it) -> second;
				int y2 = prev(it) -> first;
				if (y1 - y2 < M) {
					if (prev(it) != y.begin() && y1 - prev(prev(it)) -> first < M) {
						cout << -1 << endl;
						two = false;
						break;
					}
					if (found) {
						two = false;
						cout << -1 << endl;
						break;
					}
					else {
						found = true;
						ans = abs(x2 - x1 + M) * abs(y2 - y1 + M);
					}
				}
			}
			if (next(it) != y.end()) {
				int x2 = next(it) -> second;
				int y2 = next(it) -> first;
				if (y2 - y1 < M) {
					if (next(next(it)) != y.end() && next(next(it)) -> first - y1 < M) {
						cout << -1 << endl;
						two = false;
						break;
					}
					if (found) {
						two = false;
						cout << -1 << endl;
						break;
					}
					else {
						found = true;
						ans = abs(x2 - x1 + M) * abs(y1 - y2 + M);
					}
				}
			}
		}
	}
	if (two) cout << ans << endl;
}

/*
Sweep line from left to right (x coord)
Maintain a set of coord sorted by y value so that squares in the set are still able to overlap (ie x coord of squares in the set must be less than K distance away from the current x coord)
Use lower_bound to find if there is any y coord in the set where the distance to the current y coord is less than K
If there are more than 1 -> -1
*/