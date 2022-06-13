#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll L, N, B;
vector<vector<pair<ll, pair<ll, ll>>>> v;

int main() {
	cin >> L >> N >> B;
	for (ll i = 0; i <= L; i++) {
		v.push_back({});
	}
	ll x, l, c, f;
	for (ll i = 0; i < N; i++) {
		cin >> x >> l >> c >> f;
		v[x + l].push_back({x, {c, f}});
	}
	ll dp[1001][1001];
	for (ll i = 0; i <= L; i++) {
		for (ll j = 0; j <= B; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for (ll i = 1; i <= L; i++) {
		for (ll j = 0; j < v[i].size(); j++) {
			ll start = v[i][j].first;
			ll cost = v[i][j].second.second;
			ll fun = v[i][j].second.first;
			for (ll k = 0; k <= B; k++) {
				if (dp[start][k] != -1) {
					if (k + cost < B) dp[i][k + cost] = max(dp[i][k + cost], dp[start][k] + fun);
				}
			}
		}
	}
	ll ans = -1;
	for (ll i = 0; i <= B; i++) {
		ans = max(ans, dp[L][i]);
	}
	cout << ans << endl;
}

/*
Dp[i][j] is defined as the maximum fun rating at length i and cost j
Sort components by endpoint
For each component with start, end, fun and cost, loop through the dp row of start to update dp
*/