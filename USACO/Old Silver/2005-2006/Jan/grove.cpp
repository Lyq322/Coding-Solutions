#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	char arr[50][50];
	int di[8] = {0, 1, -1, 0, 1, 1, -1, -1};
	int dj[8] = {1, 0, 0, -1, 1, -1, 1, -1};
	int max_y = -1;
	int max_x = 0;
	int sx, sy;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X' && max_y < j) {
				max_y = j;
				max_x = i;
			}
			if (arr[i][j] == '*') {
				sx = i;
				sy = j;
			}
		}
	}
	max_y++;
	queue<pair<int, pair<int, int>>> q;
	int visited[50][50] = {{0}};
	visited[sx][sy] = 1;
	q.push({0, {sx, sy}});
	int ans = 0;
	while (!q.empty()) {
		int dist = q.front().first;
		pair<int, int> pos = q.front().second;
		q.pop();
		if (pos.first == max_x && pos.second == max_y) {
			ans += dist;
			break;
		}
		for (int i = 0; i < 8; i++) {
			int a = di[i] + pos.first;
			int b = dj[i] + pos.second;
			if (a >= 0 && b >= 0 && a < N && b < M && visited[a][b] == 0 && arr[a][b] != 'X') {
				visited[a][b] = dist + 1;
				q.push({dist + 1, {a, b}});
			}
		}
	}
	if (visited[max_x + 1][max_y] + 1 == ans || visited[max_x + 1][max_y - 1] + 1 == ans) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = 0;
			}
		}
		visited[max_x][max_y] = 1;
		visited[max_x + 1][max_y] = 1;
		visited[max_x + 1][max_y - 1] = 1;
		while (!q.empty()) q.pop();
		q.push({1, {max_x, max_y}});
		while (!q.empty()) {
			int dist = q.front().first;
			pair<int, int> pos = q.front().second;
			q.pop();
			if (pos.first == sx && pos.second == sy) {
				ans += dist;
				break;
			}
			for (int i = 0; i < 8; i++) {
				int a = di[i] + pos.first;
				int b = dj[i] + pos.second;
				if (a >= 0 && b >= 0 && a < N && b <= max_y && visited[a][b] == 0 && arr[a][b] != 'X') {
					visited[a][b] = dist + 1;
					q.push({dist + 1, {a, b}});
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = 0;
			}
		}
		visited[max_x][max_y] = 1;
		visited[max_x - 1][max_y] = 1;
		visited[max_x - 1][max_y - 1] = 1;
		while (!q.empty()) q.pop();
		q.push({1, {max_x, max_y}});
		while (!q.empty()) {
			int dist = q.front().first;
			pair<int, int> pos = q.front().second;
			q.pop();
			if (pos.first == sx && pos.second == sy) {
				ans += dist;
				break;
			}
			for (int i = 0; i < 8; i++) {
				int a = di[i] + pos.first;
				int b = dj[i] + pos.second;
				if (a >= 0 && b >= 0 && a < N && b <= max_y && visited[a][b] == 0 && arr[a][b] != 'X') {
					visited[a][b] = dist + 1;
					q.push({dist + 1, {a, b}});
				}
			}
		}
	}
	cout << ans - 1 << endl;
}

/*
We have a special condition where Bessie needs to walk around the grove
Notice that Bessie have to pass the location 1 unit up of the tree with maximum y value at some point (any of the max_y, min_y, min_x, max_x works)
This means we can first have a BFS from start to that point, then another BFS from that point to start, making sure to travel the other way around by marking the already visited way in an visited array
*/