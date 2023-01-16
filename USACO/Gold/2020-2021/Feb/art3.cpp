#include <bits/stdc++.h>
using namespace std;

// Range dp

int main() {
	int dp[305][305] = {{0}};
	int N;
	int arr[300];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = N - 1; i > -1; i--) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] == arr[j]) {
				dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
			}
			for (int k = i + 1; k < j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	cout << N - dp[0][N - 1] << endl;
}