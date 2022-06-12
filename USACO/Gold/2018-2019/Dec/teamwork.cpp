#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v;

int main() {
	cin >> N >> K;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
	int dp[10001] = {0};
	for (int i = 1; i <= N; i++) {
		int maximum = v[i - 1];
		for (int j = i; j >= max(1, i - K + 1); j--) {
			maximum = max(maximum, v[j - 1]);
			dp[i] = max(dp[i], maximum * (i - j + 1) + dp[j - 1]);
		}
	}
	cout << dp[N - 1] << endl;
}

/*
Dp[i] is defined as the best answer when using cows 1-i
Instead of calculating the maximum for each possible group (which takes O(NK^2) total), keep track of the maximum and update it every time the group size increases (lowers the complexity down to O(NK))
*/