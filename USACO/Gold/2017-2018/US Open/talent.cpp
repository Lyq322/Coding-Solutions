#include <bits/stdc++.h>
using namespace std;

/*
Knapsack dp on talent
Let dp[i][j] be the minimum weight when using the first i cows and the talent is at j
Time complexity is very tight; official solution is faster
*/

int main() {
	int N, M;
	cin >> N >> M;
	int w, t;
	pair<int, int> arr[250];
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> w >> t;
		arr[i] = {w, t};
		total += t;
	}
	int dp[2][250001] = {{0}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= total; j++) {
			dp[i % 2][j] = -1;
		}
	}
	dp[0][0] = 0;
	pair<int, int> ans = {-1, -1};
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= total; j++) {
			if (j >= arr[i - 1].second && dp[(i + 1) % 2][j - arr[i - 1].second] != -1) {
				dp[i % 2][j] = dp[(i + 1) % 2][j - arr[i - 1].second] + arr[i - 1].first;
				if (dp[(i + 1) % 2][j] != -1) {
					dp[i % 2][j] = min(dp[i % 2][j], dp[(i + 1) % 2][j]);
				}
			}
			else if (dp[(i + 1) % 2][j] != -1) {
				dp[i % 2][j] = dp[(i + 1) % 2][j];
			}
			if (dp[i % 2][j] >= M) {
				if (ans.first == -1 || (long long) ans.first * dp[i % 2][j] < (long long) j * ans.second) {
					ans = {j, dp[i % 2][j]};
				}
			}
		}
	}
	cout << ans.first * 1000 / ans.second << endl;
}
