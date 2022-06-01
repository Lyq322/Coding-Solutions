#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll cows[300000];

int main() {
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> cows[i];
	}
	vector<pair<ll, ll>> cur;
	ll ans = 0;
	for (ll i = 0; i < N; i++) {
		if (cur.size() == 0 || cows[i] < cur[cur.size() - 1].first) {
			if (cur.size() != 0) {
				ans += i - cur[cur.size() - 1].second + 1;
			}
			cur.push_back({cows[i], i});
		}
		else {
			while (cur.size() != 0) {
				if (cows[i] > cur[cur.size() - 1].first) {
					cur.pop_back();
				}
				else {
					break;
				}
			}
			if (cur.size() > 0) ans += i - cur[cur.size() - 1].second + 1;
			cur.push_back({cows[i], i});
		}
	}
	cur.clear();
	for (ll i = N - 1; i > -1; i--) {
		if (cur.size() == 0 || cows[i] < cur[cur.size() - 1].first) {
			if (cur.size() != 0) {
				ans += cur[cur.size() - 1].second - i + 1;
			}
			cur.push_back({cows[i], i});
		}
		else {
			while (cur.size() != 0) {
				if (cows[i] > cur[cur.size() - 1].first) {
					cur.pop_back();
				}
				else {
					break;
				}
			}
			if (cur.size() > 0) ans += cur[cur.size() - 1].second - i + 1;
			cur.push_back({cows[i], i});
		}
	}
	cout << ans << endl;
}
