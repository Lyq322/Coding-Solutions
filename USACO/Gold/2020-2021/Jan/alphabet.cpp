#include <bits/stdc++.h>
using namespace std;

/*
There are 20 letters, and O(2^N) is fast enough
Define dp[i] as the # of times only considering a subset of the 20 letters. What letters are in the subset is determined by the binary representation of i (1 = used)
Notice that the # of times the alphabet is hummed is the number of pairs a b where letter b is in front of or the same letter as letter a in the alphabet
So for a subset S – dp[S] = min(dp[S / i] + adj[i][all letters]), loop over i
*/

int main() {
	string s;
	cin >> s;
	int adj[20][20] = {{0}};
	map<char, int> m;
	int index = 0;
	for (int i = 0; i < s.size(); i++) {
		if (m.find(s[i]) == m.end()) {
			m[s[i]] = index;
			index++;
		}
	}
	for (int i = 0; i < s.size() - 1; i++) {
		adj[m[s[i]]][m[s[i + 1]]]++;
	}
	int dp[1048576];
	for (int i = 0; i < 1048576; i++) {
		dp[i] = 1000000;
	}
	dp[0] = 1;
	for (int i = 1; i < (1 << m.size()); i++) {
		for (int j = 0; j < 20; j++) {
			if (i & (1 << j)) {
				int t = i ^ (1 << j);
				int count = adj[j][j];
				for (int k = 0; k < 20; k++) {
					if (t & (1 << k)) {
						count += adj[j][k];
					}
				}
				dp[i] = min(dp[i], dp[t] + count);
			}
		}
	}
	cout << dp[(1 << m.size()) - 1] << endl;
}
