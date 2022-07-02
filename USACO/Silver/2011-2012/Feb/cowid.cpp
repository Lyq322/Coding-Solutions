#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
	cin >> N >> K;
	int dp[100001][11] = {{0}};
	dp[0][0] = 1;
	for (int i = 0; i <= 100001; i++) {
		dp[i][0] = 1;
	}
	int t = 0;
	int a = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
		if (t + dp[i][K - 1] <= N - 1) {
			t += dp[i][K - 1];
		}
		else {
			a = i - 1;
			break;
		}
	}
	for (int i = 0; i <= N; i++) {
	}
	int ones = K - 1;
	cout << 1;
	for (int i = a; i > 0; i--) {
		if (t == N - 1) cout << 0;
		else {
			if (t + dp[i][ones] <= N - 1) {
				cout << 1;
				t += dp[i][ones];
				ones--;
			}
			else {
				cout << 0;
			}
		}
	}
	if (a != 0) {
    	if (ones == 1) cout << 1;
    	else cout << 0;
    }
	cout << endl;
}
