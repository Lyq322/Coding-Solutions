#include <bits/stdc++.h>
using namespace std;

char grid[8][8];
int visited[8] = {0};
int diagonal_d[15] = {0};
int diagonal_s[15] = {0};
int ans = 0;

void solve(int row) {
	if (row == 8) {
		ans++;
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (!visited[i] && !diagonal_d[i - row + 7] && !diagonal_s[i + row] && grid[row][i] == '.') {
			visited[i] = true;
			diagonal_d[i - row + 7] = true;
			diagonal_s[i + row] = true;
			solve(row + 1);
			visited[i] = false;
			diagonal_d[i - row + 7] = false;
			diagonal_s[i + row] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> grid[i][j];
		}
	}
	solve(0);
	cout << ans << endl;
}
