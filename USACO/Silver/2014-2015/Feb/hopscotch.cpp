#include <bits/stdc++.h>
using namespace std;

int R, C, K;
int arr[100][100];
long long dp[100][100] = {{0}};

int main() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i < R; i++) {
		for (int j = 1; j < C; j++) {
			for (int k = 0; k < i; k++) {
				for (int l = 0; l < j; l++) {
					if (arr[i][j] != arr[k][l]) {
						dp[i][j] += dp[k][l];
					}
				}
			}
		}
	}
	cout << dp[R - 1][C - 1] << endl;
}
