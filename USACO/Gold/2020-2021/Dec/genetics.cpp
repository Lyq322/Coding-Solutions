#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
To turn this problem into dp, first we have to notice that we can split the original string into substrings, where each of these substrings has been reversed in the original string and satisfies 2 requirements
	1. No same adjacent letters (these would need to be split into 2)
	2. For all pairs of substring s1 and s2 with s1 right before s2, the first letter of s1 = the last letter of s2
To start, use 1 state to keep track of the current index
For transitions, it is easier to add 1 char at a time to current string than to add an entire substring (less transitions)
	This means that the current dp might not satisfy the requirements, so we need to keep track of the first letter of the previous substring and the last letter of the current substring and make sure they are equal when we find the answer
Finally, to avoid duplicates when adding, we also need a state that specifies the first letter of the current substring
Therefore define dp[i][j][k][l] as the number of ways to split the string from 0 to index i into substrings where all substrings satisfies the requirement except for the current one, and such that l is the last char of the current substring, k is the first letter of the current substring, j is the first letter of the previous substring
Now we only have 2 transitions (instead of N)
	1. Add 1 char to current substring
		Only requirement is cur char != previous char
	2. Start new substring
		Only requirement is for the previous substring to satisfy the requirements — k == l
*/

ll mod = 1e9 + 7;

int main() {
	string s;
	cin >> s; 
	// dp[index][first letter second to last string][first letter last string][last letter last string]
	ll dp[100001][4][4][4] = {{{{0}}}};
	map<char, int> m = {{'A', 0},
						{'C', 1},
						{'T', 2},
						{'G', 3}};
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4; k++) {
			if (s[0] == '?' || k == m[s[0]]) {
				dp[0][j][k][k] = 1;
			}
		}
	}
	for (int i = 1; i < s.length(); i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					if (s[i] != '?' && m[s[i]] != l) continue;
					if (k == l) {
						for (int old_j = 0; old_j < 4; old_j++) {
							dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][old_j][j][old_j]) % mod;
						}
					}
					for (int old_l = 0; old_l < 4; old_l++) {
						if (l != old_l) dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j][k][old_l]) % mod;
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4; k++) {
			ans = (ans + dp[s.length() - 1][j][k][j]) % mod;
		}
	}
	cout << ans << endl;
}