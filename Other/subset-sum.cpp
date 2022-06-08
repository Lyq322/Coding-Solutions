#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
ll dp[40][781] = {{0}};

int main() {
	cin >> N;
	if ((N * (N + 1)) % 4 != 0) {
		cout << 0 << endl;
	}
	else {
		for (ll i = 0; i <= N; i++) {
			dp[i][0] = 1;
		}
		for (ll i = 1; i <= N; i++) {
			for (ll j = 1; j <= N * (N + 1) / 2; j++) {
				if (j >= i) dp[i][j] += dp[i - 1][j - i];
				dp[i][j] += dp[i - 1][j];
			}
		}
		cout << dp[N][N * (N + 1) / 4] / 2 << endl;
	}
}
