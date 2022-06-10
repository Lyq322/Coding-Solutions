#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int dp[1001][1001] = {{0}};
	for (int i = 0; i <= s1.size(); i++) {
		dp[i][0] = i;
	}
	for (int i = 0; i <= s2.size(); i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1.at(i - 1) == s2.at(j - 1)) {
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j] + 1), dp[i][j - 1] + 1);
			}
			else {
				dp[i][j] = min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
			}
		}
	}
	cout << dp[s1.size()][s2.size()] << endl;
}
