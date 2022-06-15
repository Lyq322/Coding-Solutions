#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v;
int win[3] = {1, 2, 0};

int main() {
	cin >> N >> K;
	char c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c == 'P') {
			v.push_back(1);
		}
		else if (c == 'H') {
			v.push_back(0);
		}
		else {
			v.push_back(2);
		}
	}
	int dp[100000][21][3] = {{{0}}};
	for (int i = 0; i <= K; i++) {
		dp[0][i][win[v[0]]] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == 0) {
					if (win[v[i]] == k) {
						dp[i][j][k] = dp[i - 1][j][k] + 1;
					}
					else {
						dp[i][j][k] = dp[i - 1][j][k];
					}
				}
				else {
					if (win[v[i]] == k) {
						dp[i][j][k] = max(max(max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]), dp[i - 1][j - 1][2]), dp[i - 1][j][k]) + 1;
					}
					else {
						dp[i][j][k] = max(max(max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]), dp[i - 1][j - 1][2]), dp[i - 1][j][k]);
					}
				}
			}
		}
	}
	cout << max(max(dp[N - 1][K][0], dp[N - 1][K][1]), dp[N - 1][K][2]) << endl;
}

/*
A dp array to avoid unnecessary repeated calculations
One idea is to have a 2d array that stores the index and the number of changes already made
	However, this won’t take in account what the current gesture is
⇒ 3d array
Dp[i][j][k] is defined as the maximum points possible at index i with j changes in gesture and current gesture of k
Note that for easier implementation, the winning condition can be changed to same gesture wins, and the answer would still be the same
*/