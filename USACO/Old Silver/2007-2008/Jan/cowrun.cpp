#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int dp[10001][501] = {{0}};
	int diagonal[10520] = {0};
	int arr[10000];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j == 0) {
				int maximum = 0;
				for (int k = 0; k <= M; k++) {
					if (i - k < 0) break;
					maximum = max(maximum, dp[i - k][k]);
				}
				dp[i][j] = maximum;
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + arr[i - 1];
			}
		}
	}
	cout << dp[N][0] << endl;
}
/*
Dp[i][j] is defined as the maximum distance at distance i with exhaustion j
j == 0
	Currently resting
j != 0
	Currently running since Bessie have to rest until exhaustion = 0
*/