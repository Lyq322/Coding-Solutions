#include <bits/stdc++.h>
using namespace std;

int C, H;
vector<int> v;

int main() {
	cin >> C >> H;
	int a;
	for (int i = 0; i < H; i++) {
		cin >> a;
		v.push_back(a);
	}
	bool dp[2][50001] = {{0}};
	dp[0][0] = true;
	dp[1][0] = true;
	for (int i = 1; i <= H; i++) {
		for (int j = 0; j <= C; j++) {
			if (i % 2 == 1) {
				if (j >= v[i - 1]) {
					dp[1][j] = dp[0][j - v[i - 1]];
				}
				dp[1][j] = dp[1][j] || dp[0][j];
			}
			else {
				if (j >= v[i - 1]) {
					dp[0][j] = dp[1][j - v[i - 1]];
				}
				dp[0][j] = dp[0][j] || dp[1][j];
			}
		}
	}
	for (int i = C; i > -1; i--) {
		if (dp[H % 2][i]) {
			cout << i << endl;
			break;
		}
	}
}

// Bottom up knapsack with memory optimization