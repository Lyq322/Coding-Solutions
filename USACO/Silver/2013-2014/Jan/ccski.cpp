#include <bits/stdc++.h>
#include <cerrno>
#include <cinttypes>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M;
int height[500][500];
int waypoint[500][500];
int di[4] = {0, 1, -1, 0};
int dj[4] = {1, 0, 0, -1};
int total_w = 0;

bool check(int m) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (waypoint[i][j] == 1) {
				queue<pii> q;
				q.push({i, j});
				bool visited[500][500] = {{0}};
				visited[i][j] = true;
				int t = 1;
				while (!q.empty()) {
					pii pos = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int a = di[k] + pos.first;
						int b = dj[k] + pos.second;
						if (a >= 0 && b >= 0 && a < N && b < M && !visited[a][b] && abs(height[a][b] - height[pos.first][pos.second]) <= m) {
							q.push({a, b});
							visited[a][b] = true;
							if (waypoint[a][b] == 1) {
								t++;
							}
						}
					}
				}
				if (t == total_w) return true;
				else return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> height[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> waypoint[i][j];
			if (waypoint[i][j] == 1) total_w++;
		}
	}
	int l = 0;
	int r = 1000000000;
	int m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (check(m) && (m == 0 || !check(m - 1))) {
			cout << m << endl;
			break;
		}
		else if (check(m)) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
}

/*
Standard binary search question with bin search on answer
BFS to check
*/