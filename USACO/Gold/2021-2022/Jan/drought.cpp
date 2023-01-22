#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	int arr[100];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	if (N % 2 == 0) {
		ll dp[100][1001] = {{0}};
		for (int i = 0; i <= min(arr[0], arr[1]); i++) {
			dp[0][i] = 1;
			dp[1][i] = 1;
		}
		for (int i = 2; i < N; i++) {
			for (int j = 0; j <= min(arr[i - 1], arr[i]); j++) {
				for (int k = 0; k <= arr[i - 1] - j; k++) {
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i <= 1000; i++) {
			ans = (ans + dp[N - 1][i]) % mod;
		}
		cout << ans << endl;
	}
	else {
		int minimum = 1001;
		for (int i = 0; i < N; i++) {
			minimum = min(minimum, arr[i]);
		}
		ll ans = 0;
		for (int i = 0; i <= minimum; i++) {
			ll dp[100][1001] = {{0}};
			int copy_arr[100];
			for (int j = 0; j < N; j++) {
				copy_arr[j] = arr[j] - i;
			}
			for (int i = 0; i <= min(copy_arr[0], copy_arr[1]); i++) {
				dp[0][i] = 1;
				dp[1][i] = 1;
			}
			for (int i = 2; i < N; i++) {
				ll ps[1001] = {0};
				ps[0] = dp[i - 1][0];
				for (int j = 1; j <= copy_arr[i - 1]; j++) {
					ps[j] = (ps[j - 1] + dp[i - 1][j]) % mod;
				}
				for (int j = 0; j <= min(copy_arr[i - 1], copy_arr[i]); j++) {
					dp[i][j] = ps[copy_arr[i - 1] - j];
				}
			}
			for (int i = 0; i <= 1000; i++) {
				ans = (ans + dp[N - 1][i]) % mod;
			}
		}
		cout << ans << endl;
	}
}
