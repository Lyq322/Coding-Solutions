#include <bits/stdc++.h>
using namespace std;

// Sadly 7/10, don’t know what the bug is :(

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a == M) continue;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	// Define dp[i][j][k].first as the minimum staleness when Bessie has already ate 
	// bales i through j and is currently is i if k == 0 or j if k == 1
	// dp[i][j][k].second as the current time
	pair<int, int> dp[1001][1001][2];
	int index;
	for (int i = 0; i < N; i++) {
		if (v[i] > M) {
			index = i;
			break;
		}
	}
	reverse(v.begin(), v.begin() + index);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i][j][0] = {1000000000, -1};
			dp[i][j][1] = {1000000000, -1};
		}
	}
	dp[0][0][0] = {0, 0};
	dp[0][0][1] = {0, 0};
	for (int i = 1; i <= index; i++) {
		dp[i][0][0].first = dp[i - 1][0][0].first + abs(v[i - 1] - M);
		dp[i][0][1].first = dp[i - 1][0][0].first + abs(v[i - 1] - M);
		dp[i][0][0].second = abs(v[i - 1] - M);
		dp[i][0][1].second = abs(v[i - 1] - M);
	}
	for (int i = 1; i <= N - index; i++) {
		dp[0][i][0].first = dp[0][i - 1][1].first + abs(v[i + index - 1] - M);
		dp[0][i][1].first = dp[0][i - 1][1].first + abs(v[i + index - 1] - M);
		dp[0][i][0].second = abs(v[i + index - 1] - M);
		dp[0][i][1].second = abs(v[i + index - 1] - M);
	}
	for (int i = 1; i <= index; i++) {
		for (int j = 1; j <= N - index; j++) {
			if (i != 1) {
				if (dp[i - 1][j][0].first + dp[i - 1][j][0].second + abs(v[i - 1] - v[i - 2]) < dp[i - 1][j][1].first + dp[i - 1][j][1].second + abs(v[index + j - 1] - v[i - 1]) || (dp[i - 1][j][0].first + dp[i - 1][j][0].second + abs(v[i - 1] - v[i - 2]) == dp[i - 1][j][1].first + dp[i - 1][j][1].second + abs(v[index + j - 1] - v[i - 1]) && dp[i - 1][j][0].second + abs(v[i - 1] - v[i - 2]) <= dp[i - 1][j][1].second + abs(v[index + j - 1] - v[i - 1]))) {
					dp[i][j][0].second = dp[i - 1][j][0].second + abs(v[i - 1] - v[i - 2]);
					dp[i][j][0].first = dp[i][j][0].second + dp[i - 1][j][0].first; 
				}
				else {
					dp[i][j][0].first = dp[i - 1][j][1].first + dp[i - 1][j][1].second + abs(v[index + j - 1] - v[i - 1]);
					dp[i][j][0].second = dp[i - 1][j][1].second + abs(v[index + j - 1] - v[i - 1]);
				}
			}
			else {
				dp[i][j][0].first = dp[0][j][0].first + dp[0][j][0].second + abs(v[j + index - 1] - v[i - 1]);
				dp[i][j][0].second = dp[0][j][0].second + abs(v[index + j - 1] - v[i - 1]);
			}
			if (j != 1) {
				if (dp[i][j - 1][1].first + dp[i][j - 1][1].second + abs(v[j + index - 1] - v[j + index - 2]) < dp[i][j - 1][0].first + dp[i][j - 1][0].second + abs(v[i - 1] - v[index + j - 1]) && (dp[i][j - 1][1].first + dp[i][j - 1][1].second + abs(v[j + index - 1] - v[j + index - 2]) < dp[i][j - 1][0].first + dp[i][j - 1][0].second + abs(v[i - 1] - v[index + j - 1]) && dp[i][j - 1][1].second + abs(v[j + index - 1] - v[j + index - 2]) <= dp[i][j - 1][0].second + abs(v[i - 1] - v[index + j - 1]))) {
					dp[i][j][1].first = dp[i][j - 1][1].first + dp[i][j - 1][1].second + abs(v[j + index - 1] - v[j + index - 2]);
					dp[i][j][1].second = dp[i][j - 1][1].second + abs(v[j + index - 1] - v[j + index - 2]);
				}
				else {
					dp[i][j][1].first = dp[i][j - 1][0].first + dp[i][j - 1][0].second + abs(v[i - 1] - v[index + j - 1]);
					dp[i][j][1].second = dp[i][j - 1][0].second + abs(v[i - 1] - v[index + j - 1]);
				}
			}
			else {
				dp[i][j][1].first = dp[i][0][1].first + dp[i][0][1].second + abs(v[i - 1] - v[j + index - 1]);
				dp[i][j][1].second = dp[i][0][1].second + abs(v[i - 1] - v[j + index - 1]);
			}
		}
	}
	cout << min(dp[index][N - index][0].first, dp[index][N - index][1].first) << endl;
}
