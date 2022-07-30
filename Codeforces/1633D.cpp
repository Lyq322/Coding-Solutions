#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int b[1000];
		int c[1000];
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		int dp[1001];
		for (int i = 1; i < 1001; i++) {
			dp[i] = 10000;
		}
		dp[1] = 0;
		int maximum = 0;
		for (int i = 1; i <= 1000; i++) {
			if (dp[i] != 10000) {
				for (int j = 1; j <= i; j++) {
					if (i + i / j <= 1000) dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
				}
			}
			maximum = max(maximum, dp[i]);
		}
		for (int i = 0; i < n; i++) {
			b[i] = dp[b[i]];
		}
		int dp2[1001][12001] = {{0}};
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= min(12 * n, m); j++) {
				// take
				if (b[i - 1] <= j) {
					dp2[i][j] = dp2[i - 1][j - b[i - 1]] + c[i - 1];
				}
				// don't take
				dp2[i][j] = max(dp2[i][j], dp2[i - 1][j]);
				ans = max(ans, dp2[i][j]);
			}
		}
		cout << ans << endl;
	}
}

/*
N is small enough for N^2
We can precompute the number of moves from 1 to all i (up to 1000) using dp/bfs
Dp knapsack after
O(NK), however this is too slow
Notice that the highest # of moves from 1 to i is 12, so the highest number of total moves is 12 * N, which is max 12000 < 1000000
O(N * min(12N, K))
*/