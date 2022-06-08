#include <bits/stdc++.h>
using namespace std;

int N, C;
pair<int, int> arr[1000];

int main() {
	cin >> N >> C;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr[i] = {a, b};
	}
	int dp[1001][5001] = {{0}};
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= C; j++) {
			if (j >= arr[i - 1].first) dp[i][j] = dp[i - 1][j - arr[i - 1].first] + arr[i - 1].second;
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	cout << dp[N][C] << endl;
}
