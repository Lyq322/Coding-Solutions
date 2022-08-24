#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int arr[1500];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int d = (M - 1) / (N - 1);
	int r = M - 1 - (N - 1) * d;
	// dp[i][j] defined as the minimum distance needed for the first i cows with j (d + 1)'s
	pair<int, int> dp[1501][1501];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i][j] = {100000000, -1};
		}
	}
	for (int i = 0; i <= r; i++) {
		dp[0][i].first = 1;
		dp[0][i].second = arr[0] - 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= r; j++) {
			dp[i][j].first = dp[i - 1][j].first + d;
			dp[i][j].second = dp[i - 1][j].second + abs(arr[i] - dp[i][j].first);
			if (i == j || (j != 0 && dp[i][j].second > dp[i - 1][j - 1].second + abs(arr[i] - dp[i - 1][j - 1].first - d - 1))) {
				dp[i][j].first = dp[i - 1][j - 1].first + d + 1;
				dp[i][j].second = dp[i - 1][j - 1].second + abs(arr[i] - dp[i][j].first);
			}
		}
	}
	cout << dp[N - 1][r].second << endl;
}
 