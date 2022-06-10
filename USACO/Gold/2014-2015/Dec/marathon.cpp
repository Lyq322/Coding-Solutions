#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<pair<int, int>> v;

int dist(int a, int b) {
	return abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
}

int main() {
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	int dp[501][501] = {{0}};
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = dp[i - 1][j] + dist(i - 1, i);
			for (int k = 0; k < i; k++) {
				if (j - (i - k - 1) >= 0) dp[i][j] = min(dp[i][j], dp[k][j - (i - k - 1)] + dist(k, i));
			}
		}
	}
	cout << dp[N - 1][K] << endl;
}
