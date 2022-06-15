#include <bits/stdc++.h>
using namespace std;

int N;
int cow1[1000];
int cow2[1000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cow1[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> cow2[i];
	}
	int dp[1001][1001] = {{0}};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (abs(cow1[i] - cow2[j]) <= 4) {
				dp[i][j] = max(max(dp[i - 1][j - 1] + 1, dp[i - 1][j]), dp[i][j - 1]);
			}
			else {
				dp[i][j] = max(max(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]);
			}
		}
	}
	cout << dp[N][N] << endl;
}

/*
Dp[i][j] is defined as the maximum crosswalks when using the first i cows on one side of the road and first j cows on the other side
There are two cases
	Use a crosswalk from cow i-1 (0 index) to cow j-1 (if possible)
	Not use a crosswalk because there have been a crosswalk connecting either cow i-1 to a previous cow on the other side or to cow j-1 to a previous cow on the other side
*/
