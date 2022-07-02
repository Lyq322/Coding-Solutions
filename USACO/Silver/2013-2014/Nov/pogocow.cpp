#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1000][1000];
pair<int, int> arr[1000];

int solve1(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	for (int k = 0; k < N; k++) {
		if (k > j) continue;
		if (k == j) {
			dp[i][j] = max(dp[i][j], solve1(j, k) + arr[i].second);
			continue;
		}
		if (arr[j].first - arr[k].first > arr[i].first - arr[j].first) continue;
		dp[i][j] = max(dp[i][j], solve1(j, k) + arr[i].second);
	}
	return dp[i][j];
}

int solve2(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	for (int k = 0; k < N; k++) {
		if (k < j) continue;
		if (k == j) {
			dp[i][j] = max(dp[i][j], solve2(j, k) + arr[i].second);
			continue;
		}
		if (arr[k].first - arr[j].first > arr[j].first - arr[i].first) continue;
		dp[i][j] = max(dp[i][j], solve2(j, k) + arr[i].second);
	}
	return dp[i][j];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		dp[i][i] = arr[i].second;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i > j) {
				if (dp[i][j] == -1) {
					solve1(i, j);
				}
			}
			else if (j > i) {
				if (dp[i][j] == -1) {
					solve2(i, j);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}
