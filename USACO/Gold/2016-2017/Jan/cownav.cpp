#include <bits/stdc++.h>
using namespace std;

// BFS with state that has position, dir and bool finished of Bessie if starting facing up, position, dir and bool finished  of Bessie if starting facing right, current dist

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
// right, down, left, up

struct Pos {
	int x1;
	int y1;
	int d1;
	int x2;
	int y2;
	int d2;
	int dist;
	bool x;
	bool y;
};

int main() {
	int N;
	cin >> N;
	char arr[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	bool visited[20][20][4][20][20][4][2][2];
	visited[N - 1][0][0][N - 1][0][3][0][0] = true;
	queue<Pos> q;
	q.push({N - 1, 0, 0, N - 1, 0, 3, 0, false, false});
	while (!q.empty()) {
		Pos p = q.front();
		q.pop();
		if (p.x1 == 0 && p.y1 == N - 1) {
			p.x = true;
		}
		if (p.x2 == 0 && p.y2 == N - 1) {
			p.y = true;
		}
		if (p.x && p.y) {
			cout << p.dist << endl;
			break;
		}
		Pos new_p = p;
		new_p.d1 = (new_p.d1 + 1) % 4;
		new_p.d2 = (new_p.d2 + 1) % 4;
		new_p.dist++;
		if (!visited[new_p.x1][new_p.y1][new_p.d1][new_p.x2][new_p.y2][new_p.d2][new_p.x][new_p.y]) {
			visited[new_p.x1][new_p.y1][new_p.d1][new_p.x2][new_p.y2][new_p.d2][new_p.x][new_p.y] = true;
			q.push(new_p);
		}
		new_p = p;
		new_p.d1 = (new_p.d1 + 3) % 4;
		new_p.d2 = (new_p.d2 + 3) % 4;
		new_p.dist++;
		if (!visited[new_p.x1][new_p.y1][new_p.d1][new_p.x2][new_p.y2][new_p.d2][new_p.x][new_p.y]) {
			visited[new_p.x1][new_p.y1][new_p.d1][new_p.x2][new_p.y2][new_p.d2][new_p.x][new_p.y] = true;
			q.push(new_p);
		}
		new_p = p;
		int a = new_p.x1 + di[new_p.d1];
		int b = new_p.y1 + dj[new_p.d1];
		if (a >= 0 && a < N && b >= 0 && b < N && arr[a][b] == 'E') {
			new_p.x1 = a;
			new_p.y1 = b;
		}
		a = new_p.x2 + di[new_p.d2];
		b = new_p.y2 + dj[new_p.d2];
		if (a >= 0 && a < N && b >= 0 && b < N && arr[a][b] == 'E') {
			new_p.x2 = a;
			new_p.y2 = b;
		}
		new_p.dist++;
		if (!visited[new_p.x1][new_p.y1][new_p.d1][new_p.x2][new_p.y2][new_p.d2][new_p.x][new_p.y]) {
			visited[new_p.x1][new_p.y1][new_p.d1][new_p.x2][new_p.y2][new_p.d2][new_p.x][new_p.y] = true;
			q.push(new_p);
		}
	}
}
