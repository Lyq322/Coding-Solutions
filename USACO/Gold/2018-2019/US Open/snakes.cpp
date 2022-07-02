#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int arr[400];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int dp[2][400][401] = {{{0}}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 400; j++) {
			for (int k = 0; k < 401; k++) {
				if (i != 0) dp[i][j][k] = -1;
				else dp[i][j][k] = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= min(K, i); j++) {
			int minimum = -1;
			if (j != 0) {
				for (int l = 1; l <= N; l++) {
					if (dp[(i + 1) % 2][j - 1][l] != -1 && (minimum == -1 || minimum > dp[(i + 1) % 2][j - 1][l])) {
						minimum = dp[(i + 1) % 2][j - 1][l];
					}
				}
			}
			for (int k = 1; k <= N; k++) {
				dp[i % 2][j][k] = -1;
				if (arr[k - 1] < arr[i - 1]) {
					dp[i % 2][j][k] = -1;
					continue;
				}
				if (minimum != -1) dp[i % 2][j][k] = minimum + arr[k - 1] - arr[i - 1];
				if (dp[(i + 1) % 2][j][k] != -1) {
					if (dp[i % 2][j][k] == -1) dp[i % 2][j][k] = dp[(i + 1) % 2][j][k] + arr[k - 1] - arr[i - 1];
					else dp[i % 2][j][k] = min(dp[i % 2][j][k], dp[(i + 1) % 2][j][k] + arr[k - 1] - arr[i - 1]);
				}
			}
		}
	}
	int ans = -1;
	for (int i = 1; i <= N; i++) {
		if (dp[N % 2][K][i] != -1) {
			if (ans == -1 || ans > dp[N % 2][K][i]) ans = dp[N % 2][K][i];
		}
	}
	cout << ans << endl;
}

/*
Dp[i][j][k] is defined as the minimum wasted space for the first i snakes with j changes and the current net size as arr[k] (arr is from input)
Bottom up approach by looping over dp
	Two cases, change net or don’t change net
	Change net
		Loop over possible l in dp[i - 1][j - 1][l] to find minimum
		This can be done outside the for k loop to maintain an O(N^3) solution
	Don’t change net
		Dp[i - 1][j][k]
May need to use memory optimization
*/