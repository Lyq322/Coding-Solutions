#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v;
	int c;
	v.push_back(M);
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c == M) continue;
		v.push_back(c);
	}
	v.push_back(M);
	sort(v.begin() + 1, v.end());
	int index = N;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > M) {
			index = i;
			break;
		}
	}
	int dp[1001][1001][2] = {{{0}}};
	reverse(v.begin() + 1, v.begin() + index - 1);
	for (int i = 1; i < index - 1; i++) {
		dp[i][0][0] = dp[i - 1][0][0] + abs(v[i] - v[i - 1]) * (N - i + 1);
	}
	for (int i = 1; i <= v.size() - index; i++) {
		dp[0][i][1] = dp[0][i - 1][1] + abs(v[index + i - 2] - v[index + i - 1]) * (N - i + 1);
	}
	for (int i = 1; i < index - 1; i++) {
		dp[i][0][1] = dp[i][0][0] + abs(v[i] - M) * (N - i);
	}
	for (int i = 1; i <= v.size() - index; i++) {
		dp[0][i][0] = dp[0][i][1] + abs(v[index + i - 1] - M) * (N - i);
	}
	for (int i = 1; i <= index - 2; i++) {
		for (int j = 1; j <= v.size() - index; j++) {
			dp[i][j][0] = min(dp[i - 1][j][0] + abs(v[i - 1] - v[i]) * (N - (i + j) + 1), dp[i - 1][j][1] + abs(v[index + j - 1] - v[i]) * (N - (i + j) + 1));
			dp[i][j][1] = min(dp[i][j - 1][1] + abs(v[j + index - 2] - v[j + index - 1]) * (N - i - j + 1), dp[i][j - 1][0] + abs(v[i] - v[index + j - 1]) * (N - (i + j) + 1));
		}
	}
	cout << min(dp[index - 2][v.size() - index][0], dp[index - 2][v.size() - index][1]) << endl;
}
