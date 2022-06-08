#include <bits/stdc++.h>
using namespace std;

int N, M, T;
char grid[100][100];
int r1, r2, c1, c2;
int dp[100][100][16] = {{{0}}};
bool found[100][100][16] = {{{0}}};
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

void solve(int r, int c, int t) {
	if (found[r][c][t]) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		int a = di[i] + r;
		int b = dj[i] + c;
		if (a >= 0 && b >= 0 && a < N && b < M && grid[a][b] != '*') {
			if (t > 0) {
				solve(a, b, t - 1);
				if (found[a][b][t - 1]) {
					dp[r][c][t] += dp[a][b][t - 1];
				}
			}
		}
	}
	found[r][c][t] = true;
}

int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}
	cin >> r1 >> c1 >> r2 >> c2;
	r1--;
	r2--;
	c1--;
	c2--;
	dp[r1][c1][0] = 1;
	found[r1][c1][0] = true;
	solve(r2, c2, T);
	cout << dp[r2][c2][T] << endl;
}
