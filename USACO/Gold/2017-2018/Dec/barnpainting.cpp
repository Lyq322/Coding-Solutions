#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Root the tree at any point
Define dp[i][c] as the number of ways to color the subtree with root i that is colored as c
Don't forget to mod
*/

ll N, M;
vector<vector<ll>> barns;
ll dp[100000][4];

ll solve(ll pos, ll color, ll par) {
	if (dp[pos][color] != -1) return dp[pos][color];
	dp[pos][color] = 1;
	for (ll i = 0; i < barns[pos].size(); i++) {
		if (barns[pos][i] == par) continue;
		ll t = 0;
		for (ll j = 1; j < 4; j++) {
			if (color != j) {
				t += solve(barns[pos][i], j, pos);
				t = t % 1000000007;
			}
		}
		dp[pos][color] *= t;
		dp[pos][color] = dp[pos][color] % 1000000007;
	}
	return dp[pos][color];
}

int main() {
	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		barns.push_back({});
		dp[i][3] = -1;
		dp[i][1] = -1;
		dp[i][2] = -1;
	}
	ll a, b;
	for (ll i = 0; i < N - 1; i++) {
		cin >> a >> b;
		a--;
		b--;
		barns[a].push_back(b);
		barns[b].push_back(a);
	}
	for (ll i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		for (ll j = 1; j < 4; j++) {
			if (j != b) dp[a][j] = 0;
		}
	}
	solve(0, 1, -1);
	solve(0, 2, -1);
	solve(0, 3, -1);
	cout << (dp[0][1] + dp[0][2] + dp[0][3]) % 1000000007 << endl;
}
