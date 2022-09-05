#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int R, C, K;
	cin >> R >> C >> K;
	int grid[250][250];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> grid[i][j];
		}
	}
	ll dp[250][250];
	ll ps[251][251] = {{0}};
	dp[0][0] = 1;
	ps[1][1] = 1;
	map<int, ll> col[250];
	col[0][grid[0][0]] = 1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i == 0 && j == 0) continue;
			if (i == 0) {
				ps[i + 1][j + 1] = ps[i + 1][j];
				continue;
			}
			else if (j == 0) {
				ps[i + 1][j + 1] = ps[i][j + 1];
				continue;
			}
			dp[i][j] = ps[i][j];
			ll t = 0;
			for (int k = 0; k < j; k++) {
				if (col[k].find(grid[i][j]) != col[k].end()) {
					t = (t + col[k][grid[i][j]]) % 1000000007;
				}
				if (grid[i][k] == grid[i][j]) t = (t - dp[i][k] + 1000000007) % 1000000007;
			}
			dp[i][j] = (dp[i][j] - t + 1000000007) % 1000000007;
			ps[i + 1][j + 1] = (dp[i][j] + ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + 1000000007) % 1000000007;
			if (col[j].find(grid[i][j]) != col[j].end()) {
				col[j][grid[i][j]] = (col[j][grid[i][j]] + dp[i][j]) % 1000000007;
			}
			else col[j][grid[i][j]] = dp[i][j];
		}
	}
	cout << dp[R - 1][C - 1] << endl;
}
