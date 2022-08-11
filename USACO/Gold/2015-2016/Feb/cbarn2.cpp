#include <bits/stdc++.h>
using namespace std;

/*
Imagine the barn as a line instead of a circle; we can loop through the starting position of each line and open the door at the front of each line to simulate the circular barn
Define dp[i][j][k] as the minimum distance needed for rooms 1 to i when j keys are already used and k was the last room unlocked
	If the current room is unlocked (ie i == k), then we have to loop through last_key for k: dp[i][j][k] = min(dp[i - 1][j - 1][last_key])
	If the current room is not unlocked (ie i != k), then dp[i][j][k] is just dp[i - 1][j][k] + (i - k) * arr[i]
My code definitely has some bugs but it somehow passed all test cases??? lol
*/

int ans = 1000000000;
vector<int> v;
int N, K;

void solve() {
	int dp[101][8][101];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 101; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	dp[1][1][1] = 0;
	for (int j = 1; j <= K; j++) {
		for (int i = 2; i <= N; i++) {
			for (int k = 1; k <= i; k++) {
				if (i >= j && i == k && j > 1 && k >= j) {
					dp[i][j][k] = 1000000000;
					for (int last_key = j - 1; last_key < i; last_key++) {
						if (dp[i - 1][j - 1][last_key] != -1) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][last_key]);
					}
				}
				else if (i - 1 >= j && !(j == 1 && k != 1) && k >= j) {
					dp[i][j][k] = dp[i - 1][j][k] + (i - k) * v[i - 1];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dp[N][K][i] > 0) ans = min(ans, dp[N][K][i]);
	}
}

int main() {
	cin >> N >> K;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
	solve();
	for (int i = 1; i < N; i++) {
		rotate(v.begin(), v.begin() + 1, v.end());
		solve();
	}
	cout << ans << endl;
}
