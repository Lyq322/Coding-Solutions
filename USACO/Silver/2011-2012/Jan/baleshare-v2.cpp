#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[20];
	int t = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		t += arr[i];
	}
	bool dp[21][700][700] = {{{0}}};
	dp[0][0][0] = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 700; j++) {
			for (int k = 0; k < 700; k++) {
				dp[i][j][k] = dp[i - 1][j][k];
				if (j - arr[i - 1] >= 0) {
					dp[i][j][k] = dp[i][j][k] || dp[i - 1][j - arr[i - 1]][k];
				}
				if (k - arr[i - 1] >= 0) {
					dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k - arr[i - 1]];
				}
			}
		}
	}
	int ans = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 700; j++) {
			for (int k = 0; k < 700; k++) {
				if (dp[i][j][k] && t - j - k >= 0) {
					int temp = max(max(j, k), t - j - k);
					if (ans == -1 || ans > temp) ans = temp;
				}
			}
		}
	}
	cout << ans << endl;
}

/*
Knapsack
Dp[i][j][k](bool) is defined as if it is possible to split the first i bales into three barns so that the bales in each barn are (j, k, total - j - k)
*/