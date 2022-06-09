#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[2][10001] = {{0}};

int main() {
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1.at(i - 1) == s2.at(j - 1)) {
				dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
			}
			else {
				dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
			}
		}
	}
	cout << dp[s1.size() % 2][s2.size()] << endl;
}
