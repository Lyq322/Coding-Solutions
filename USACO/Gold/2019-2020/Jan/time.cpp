#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, C;
	cin >> N >> M >> C;
	int cities[1000];
	for (int i = 0; i < N; i++) {
		cin >> cities[i];
	}
	vector<vector<int>> adj;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
	}
	int dp[1001][1000];
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < adj[j].size(); k++) {
				if (dp[i - 1][adj[j][k]] != -1) {
					dp[i][j] = max(dp[i][j], dp[i - 1][adj[j][k]]);
				}
			}
			if (dp[i][j] != -1) dp[i][j] += cities[j];
		}
	}
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	int maximum = 0;
	for (int i = 0; i <= 1000; i++) {
		maximum = max(maximum, dp[i][0] - C * i * i);
	}
	cout << maximum << endl;
}
/*
Dp[i][j] is defined as the maximum mooney at time j and city i
For time t, the maximum mooney earned is 1000t - t^2 
(when at every city Bessie can make 1000 mooney and C = 1)
Thus t has to be <= 1000 in order to have a positive mooney
*/