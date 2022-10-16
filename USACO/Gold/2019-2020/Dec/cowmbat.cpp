#include <bits/stdc++.h>
using namespace std;

/*
Fun problem :D, very happy I thought of the solution
First, we can precompute the best way to change from letter ? to letter ? using floyd-warshall in O(M^3)
Next, always think of dp when solving gold problems. Notice that we can build up the answer using previous answers:
	Define dp[i][j] as the minimum days to change the first i letters, with the last letter being j
	The problem requires that the final string to be in segments of the same letter with size >= K
	At the current position, we can either continue the previous segment by setting the current position equal to the previous segment’s letter, or we can choose to create a new segment that is K letters long
	Translated into equations, this is min(dp[i - 1][j] + convert[cur_char][j], dp[i - K][a] + convert[i - K + 1 thr i][j]), where a loops through M and convert is the 2d array we get after we run floyd-warshall on the input
	However, the last part, convert[i - K + 1 thr i][j], requires an extra loop of length N, which is too slow
	We can optimize this using prefix sum!
	Define ps[i][j] as the sum of convert[0 the i][j]
*/
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	string s;
	cin >> s;
	int dp[100001][26] = {{0}};
	int convert[26][26];
	int ps[100001][26] = {{0}};
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cin >> convert[i][j];
		}
	}
	for (int k = 0; k < M; k++) {
		ps[0][k] = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				if (convert[i][k] + convert[k][j] < convert[i][j]) {
					convert[i][j] = convert[i][k] + convert[k][j];
				}
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= N; j++) {
			ps[j][i] = ps[j - 1][i] + convert[s.at(j - 1) - 'a'][i];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			dp[K][i] += convert[s.at(j) - 'a'][i];
		}
	}
	for (int i = K + 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			dp[i][j] = dp[i - 1][j] + convert[s.at(i - 1) - 'a'][j];
			if (i - K - K >= 0) {
				for (int k = 0; k < M; k++) {
					dp[i][j] = min(dp[i][j], dp[i - K][k] + ps[i][j] - ps[i - K][j]);
				}
			}
		}
	}
	int ans = 1000000000;
	for (int i = 0; i < M; i++) {
		ans = min(ans, dp[N][i]);
	}
	cout << ans << endl;
}

