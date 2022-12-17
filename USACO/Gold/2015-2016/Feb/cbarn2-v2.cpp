#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
int arr[100];
ll ans = -1;

void shift() {
	int temp = arr[0];
	for (int i = 0; i < N - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[N - 1] = temp;
}

void solve() {
	// dp[index][doors][prev door index]
	ll dp[100][8][100];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k < N; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	dp[0][1][0] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= min(K, i + 1); j++) {
			for (int k = 0; k <= i; k++) {
				if (i == k) {
					if (j != 1) {
						dp[i][j][k] = -1;
						for (int l = 0; l < i; l++) {
							if (dp[i - 1][j - 1][l] != -1 && (dp[i][j][k] == -1 || dp[i][j][k] > dp[i - 1][j - 1][l])) dp[i][j][k] = dp[i - 1][j - 1][l];
						}
					}
					else {
						dp[i][j][k] = -1;
					}
				}
				else {
					if (dp[i - 1][j][k] != -1) dp[i][j][k] = dp[i - 1][j][k] + arr[i] * (i - k);
				}
			}
		}
	}
	ll minimum = -1;
	for (int i = 0; i < N; i++) {
		if (dp[N - 1][K][i] != -1 && (minimum == -1 || minimum > dp[N - 1][K][i])) minimum = dp[N - 1][K][i];
	}
	if (ans == -1 || ans > minimum) {
		ans = minimum;
	}
}

int main() {
	ifstream fin("cbarn2.in");
	ofstream fout("cbarn2.out");
	fin >> N >> K;
	for (int i = 0; i < N; i++) {
		fin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		solve();
		shift();
	}
	fout << ans << endl;
}
