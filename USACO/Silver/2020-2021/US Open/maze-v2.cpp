#include <bits/stdc++.h>

using namespace std;

int N;
char grid[25][75];
bool visited[25][75][3][3][3][3][3][3][3][3][3];
int sx, sy;
int di[4] = {0, 1, 0, -1};
int dj[4] = {3, 0, -3, 0};
int board[3][3];
int winBoards[3][3][3][3][3][3][3][3][3] = {{{{{{{{{0}}}}}}}}};
int ans = 0;

bool check() {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == 1 && board[i][1] == 2 && board[i][2] == 2) {
			return true;
		}
		else if (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 1) {
			return true;
		}
		else if (board[0][i] == 1 && board[1][i] == 2 && board[2][i] == 2) {
			return true;
		}
		else if (board[0][i] == 2 && board[1][i] == 2 && board[2][i] == 1) {
			return true;
		}
	}
	if (board[0][0] == 1 && board[1][1] == 2 && board[2][2] == 2) {
		return true;
	}
	else if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 1) {
		return true;
	}
	else if (board[0][2] == 1 && board[1][1] == 2 && board[2][0] == 2) {
		return true;
	}
	else if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 1) {
		return true;
	}
	return false;
}

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int a = x + di[i];
		int b = y + dj[i];
		if (a >= 0 && b >= 0 && a < N && b < 3 * N && !visited[a][b][board[0][0]][board[0][1]][board[0][2]][board[1][0]][board[1][1]][board[1][2]][board[2][0]][board[2][1]][board[2][2]] && grid[a][b] != '#') {
			visited[a][b][board[0][0]][board[0][1]][board[0][2]][board[1][0]][board[1][1]][board[1][2]][board[2][0]][board[2][1]][board[2][2]] = true;
			bool changed = false;
			char prevLet;
			if (grid[a][b] != '.' && grid[a][b] != 'B' && board[grid[a][b + 1] - '0' - 1][grid[a][b + 2] - '0' - 1] == 0) {
				int letter;
				changed = true;
				if (grid[a][b] == 'M') {
					letter = 1;
				}
				else {
					letter = 2;
				}
				board[grid[a][b + 1] - '0' - 1][grid[a][b + 2] - '0' - 1] = letter;
				prevLet = grid[a][b];
				grid[a][b] = '.';
				if (check()) {
					if (winBoards[board[0][0]][board[0][1]][board[0][2]][board[1][0]][board[1][1]][board[1][2]][board[2][0]][board[2][1]][board[2][2]] == 0) {
						ans++;
						winBoards[board[0][0]][board[0][1]][board[0][2]][board[1][0]][board[1][1]][board[1][2]][board[2][0]][board[2][1]][board[2][2]] = 1;
					}
					board[grid[a][b + 1] - '0' - 1][grid[a][b + 2] - '0' - 1] = 0;
					grid[a][b] = prevLet;
					return;
				}
			}
			visited[a][b][board[0][0]][board[0][1]][board[0][2]][board[1][0]][board[1][1]][board[1][2]][board[2][0]][board[2][1]][board[2][2]] = true;
			dfs(a, b);
			if (changed) {
				grid[a][b] = prevLet;
				board[grid[a][b + 1] - '0' - 1][grid[a][b + 2] - '0' - 1] = 0;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3 * N; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'B') {
				sx = i;
				sy = j;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = 0;
		}
	}
	sy -= 2;
	visited[sx][sy][0][0][0][0][0][0][0][0][0] = true;
	dfs(sx, sy);
	cout << ans << endl;
}
