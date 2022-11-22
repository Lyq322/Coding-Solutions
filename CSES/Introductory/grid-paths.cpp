#include <iostream>
using namespace std;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int dir[48];
bool visited[9][9];
int ans = 0;

void solve(int count, int x, int y) {
	if (visited[x][y - 1] && visited[x][y + 1] && !visited[x - 1][y] && !visited[x + 1][y]) return;
	if (visited[x - 1][y] && visited[x + 1][y] && !visited[x][y - 1] && !visited[x][y + 1]) return;

	if (x == 7 && y == 1) {
		if (count == 48) {
			ans++;
		}
		return;
	}
	else if (count == 48) return;

	if (dir[count] != 4) {
		int a = x + di[dir[count]];
		int b = y + dj[dir[count]];
		if (!visited[a][b]) {
			visited[x][y] = true;
			solve(count + 1, a, b);
			visited[x][y] = false;
		}
	} 
	else { 
		for (int i = 0; i < 4; i++) {
			int a = x + di[i];
			int b = y + dj[i];
			if (!visited[a][b]) {
				visited[x][y] = true;
				solve(count + 1, a, b);
				visited[x][y] = false;
			}
		}
	}
}

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < 48; i++) {
		if (s[i] == 'U') dir[i] = 0;
		else if (s[i] == 'R') dir[i] = 1;
		else if (s[i] == 'D') dir[i] = 2;
		else if (s[i] == 'L') dir[i] = 3;
		else dir[i] = 4;
	}
	for (int i = 0; i < 9; i++) {
		visited[0][i] = true;
		visited[8][i] = true;
		visited[i][0] = true;
		visited[i][8] = true;
	}
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			visited[i][j] = false;
		}
	}
	solve(0, 1, 1);
	cout << ans << endl;
}