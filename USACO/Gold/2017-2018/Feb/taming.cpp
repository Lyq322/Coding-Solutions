#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100];
int dp[110][110][110] = {{{0}}};

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k < N; k++) {
				dp[i][j][k] = 1000;
			}
		}
	}
	if (arr[0] == 0) dp[0][1][0] = 0;
	else dp[0][1][0] = 1;
	for (int i = 1; i < N; i++) {
		for (int k = 0; k <= i; k++) {
			for (int j = 1; j <= i + 1; j++) {
				if (i > k) {
					dp[i][j][k] = dp[i - 1][j][k];
					if (arr[i] != i - k) dp[i][j][k]++;
				}
				else {
					for (int l = 0; l < k; l++) {
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][l]);
					}
					if (arr[i] != 0) dp[i][j][k]++;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int ans = 1000;
		for (int j = 0; j < N; j++) {
			ans = min(ans, dp[N - 1][i][j]);
		}
		cout << ans << endl;
	}
}

/*
Use a dp array to save time
We only need to calculate the dp once to get all answers
Dp[i][j] is defined as the minimum changes for the first i days when there are j breakouts
However, we don’t know the last breakout date, so we won’t know if the current day’s number is wrong or not
Dp[i][j][k] is defined as the minimum changes for the first i days when there are j breakouts and the last breakout occurs at day k
2 cases
When the last breakout is at the current i (i == k)
Loop over new_k in dp[i - 1][j - 1][new_k]
Check if the current day’s number is correct and update accordingly
*/