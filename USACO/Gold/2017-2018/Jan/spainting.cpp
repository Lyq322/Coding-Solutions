#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll N, M, K;
	cin >> N >> M >> K;
	if (K == 1) {
		long long ans = 1;
		for (ll i = 0; i < N; i++) {
			ans = (ans * M) % 1000000007;
		}
		cout << ans << endl;
		return 0;
	}
	ll dp[1000001];
	dp[1] = M;
	ll t = M;
	for (ll i = 2; i < K; i++) {
		dp[i] = (M * dp[i - 1]) % 1000000007;
		t += dp[i];
		t = t % 1000000007;
	}
	for (ll i = K; i <= N; i++) {
		dp[i] = (t * (M - 1)) % 1000000007;
		t += dp[i];
		t -= dp[i - K + 1];
		t = (t + 1000000007) % 1000000007;
	}
	ll total = 1;
	for (ll i = 1; i <= N; i++) {
		total *= M;
		total = total % 1000000007;
	}
	cout << (total - dp[N] + 1000000007) % 1000000007 << endl;
}
