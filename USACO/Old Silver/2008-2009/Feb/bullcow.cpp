#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N, K;
	cin >> N >> K;
	ll dp[100001] = {0};
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		if (i - K - 1 >= 0) {
			dp[i] = (dp[i - 1] + dp[i - K - 1]) % 5000011;
		}
		else {
			dp[i] = (dp[i - 1] + 1) % 5000011;
		}
	}
	cout << dp[N] << endl;
}

/*
Dp[i] is defined as the number of ways to arrange the bulls and cows for the first i bovines
Two cases, if the current position is a bull or cow
*/