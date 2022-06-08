#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	cin >> N;
	int a;
	int num[20000];
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	int dp[20000];
	for (int i = 0; i < N; i++) {
		int maximum = 0;
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i]) {
				maximum = max(maximum, dp[j]);
			}
		}
		dp[i] = maximum + 1;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
