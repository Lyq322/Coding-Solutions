#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int maximum = (N + 1) / 2 - 1;
	int dp[2501][5] = {{0}};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < 5; j++) {
			if (j == 1) {
				if (i > maximum) {
					dp[i][j] = 0;
				}
				else {
					dp[i][j] = 1;
				}
			}
			else {
				for (int k = min(maximum, i); k > 0; k--) {
					dp[i][j] += dp[i - k][j - 1];
				}
			}
		}
	}
	cout << dp[N][4] << endl;
}

/*
For lengths a, b, c, d to form a quadrilateral, the sum of the smallest 3 lengths need to be larger than the largest length
So the four lengths need to be smaller than the (N + 1) / 2 (N from input, N + 1 to make sure both odd and even N works)
Define dp[i][j] as the number of ways to split i into j positive integers that are less than or equal to (N + 1) / 2
*/