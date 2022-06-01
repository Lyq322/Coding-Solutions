#include <bits/stdc++.h>
using namespace std;

int M, N;
int grid[110][110] = {{0}};
int visited[110][110] = {{0}};
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
int rooms = 1;
int room_space[100000] = {0};
int max_combined = 0;
int max_room_space = 0;

void g1(int i, int j) {
	grid[i][j - 1] = 1;
	grid[i - 1][j - 1] = 1;
	grid[i + 1][j - 1] = 1;
}

void g2(int i, int j) {
	grid[i - 1][j] = 1;
	grid[i - 1][j + 1] = 1;
	grid[i - 1][j - 1] = 1;
}

void g4(int i, int j) {
	grid[i][j + 1] = 1;
	grid[i - 1][j + 1] = 1;
	grid[i + 1][j + 1] = 1;
}

void g8(int i, int j) {
	grid[i + 1][j] = 1;
	grid[i + 1][j - 1] = 1;
	grid[i + 1][j + 1] = 1;
}

void ff(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = rooms;
	int space = 1;
	int maximum = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int a = cur.first + di[i];
			int b = cur.second + dj[i];
			if (a >= 0 && b >= 0 && a < N && b < M && visited[a][b] == 0) {
				if (grid[a][b] != 1) {
					if (grid[a][b] == 2) space++;
					visited[a][b] = rooms;
					q.push({a, b});
				}
				else {
					for (int j = 0; j < 4; j++) {
						int new_a = a + di[j];
						int new_b = b + dj[j];
						if (new_a >= 0 && new_b >= 0 && new_a < N && new_b < M && visited[new_a][new_b] != 0) {
							if (visited[new_a][new_b] == visited[a][b]) continue;
							maximum = max(maximum, room_space[visited[new_a][new_b]]);
						} 
					}
				}
			}
		}
	}
	max_combined = max(max_combined, maximum + space);
	room_space[rooms] = space;
}

int main() {
	cin >> M >> N;
	int a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a;
			grid[2 * i + 1][2 * j + 1] = 2;
			// Using bitwise operators / binary is probably the better way to do this...
			if (a == 1) g1(2 * i + 1, 2 * j + 1);
			else if (a == 2) g2(2 * i + 1, 2 * j + 1);
			else if (a == 4) g4(2 * i + 1, 2 * j + 1);
			else if (a == 8) g8(2 * i + 1, 2 * j + 1);
			else if (a == 3) {
				g1(2 * i + 1, 2 * j + 1);
				g2(2 * i + 1, 2 * j + 1);
			}
			else if (a == 5) {
				g1(2 * i + 1, 2 * j + 1);
				g4(2 * i + 1, 2 * j + 1);
			}
			else if (a == 9) {
				g1(2 * i + 1, 2 * j + 1);
				g8(2 * i + 1, 2 * j + 1);
			}
			else if (a == 6) {
				g2(2 * i + 1, 2 * j + 1);
				g4(2 * i + 1, 2 * j + 1);
			}
			else if (a == 10) {
				g2(2 * i + 1, 2 * j + 1);
				g8(2 * i + 1, 2 * j + 1);
			}
			else if (a == 12) {
				g4(2 * i + 1, 2 * j + 1);
				g8(2 * i + 1, 2 * j + 1);
			}
			else if (a == 7) {
				g1(2 * i + 1, 2 * j + 1);
				g2(2 * i + 1, 2 * j + 1);
				g4(2 * i + 1, 2 * j + 1);
			}
			else if (a == 11) {
				g1(2 * i + 1, 2 * j + 1);
				g2(2 * i + 1, 2 * j + 1);
				g8(2 * i + 1, 2 * j + 1);
			}
			else if (a == 13) {
				g1(2 * i + 1, 2 * j + 1);
				g4(2 * i + 1, 2 * j + 1);
				g8(2 * i + 1, 2 * j + 1);
			}
			else if (a == 14) {
				g2(2 * i + 1, 2 * j + 1);
				g4(2 * i + 1, 2 * j + 1);
				g8(2 * i + 1, 2 * j + 1);
			}
			else if (a == 0) continue;
			else {
				g1(2 * i + 1, 2 * j + 1);
				g2(2 * i + 1, 2 * j + 1);
				g4(2 * i + 1, 2 * j + 1);
				g8(2 * i + 1, 2 * j + 1);
			}
		}
	}
	N = 2 * N + 1;
	M = 2 * M + 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0 && grid[i][j] != 1) {
				ff(i, j);
				rooms++;
			}
		}
	}
	for (int i = 1; i < rooms; i++) {
		max_room_space = max(max_room_space, room_space[i]);
	}
	cout << rooms - 1 << endl;
	cout << max_room_space << endl;
	cout << max_combined << endl;
}

/*
Idea
	Use flood fill to find the # of rooms and the largest room’s area easily
	While using FF, find any neighboring rooms to find the maximum area of two rooms combined
*/