#include <bits/stdc++.h>
using namespace std;

/*
We can interpret the expanding of the robots in a different way — after the robot has expanded x times, the surrounding robots will all be within x steps away of the center of the robot (the original one)
This means we can find where the center of the robot can move to using the distance from any location to the nearest #
	This can be done using a BFS
Once we have that info, we can start a multi-source bfs starting at each starting position to find all locations the center robot can go to and what the size of the current robot group at that position
Finally, using a another multi-source bfs from each center position with size s, with priority queue prioritizing the robot with the greatest size
	We can decrease s by one each time the robot moves, until it gets to 0 to simulate the “within x steps away from center robot”
*/

int dp[1000][1000];
int di[4] = {0, 1, -1, 0};
int dj[4] = {1, 0, 0, -1};
char arr[1000][1000] = {{0}};
int N, M;

struct Pos {
	pair<int, int> pos;
	int dist;
};

bool operator<(Pos a, Pos b) {
	return a.dist < b.dist;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j];
			dp[i][j] = -1;
		}
	}
	bool visited[1000][1000] = {{0}};
	int visited2[1000][1000] = {{0}};
	queue<pair<pair<int, int>, int>> q2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '#') {
				q2.push({{i, j}, 0});
				dp[i][j] = 0;
				visited[i][j] = true;
			}
		}
	}
	while (!q2.empty()) {
		pair<int, int> cur = q2.front().first;
		int d = q2.front().second;
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int a = cur.first + di[i];
			int b = cur.second + dj[i];
			if (a >= 0 && b >= 0 && a < N && b < N && !visited[a][b]) {
				visited[a][b] = true;
				dp[a][b] = d + 1;
				q2.push({{a, b}, d + 1});
			}
		}
	}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'S') {
				q.push({{i, j}, {0, 1}});
				visited2[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front().first;
		int time = q.front().second.first;
		int range = q.front().second.second;
		q.pop();
		if (time % M == 0 && time != 0) {
			if (range + 1 > dp[cur.first][cur.second]) {
				continue;
			}
			else {
				range++;
				visited2[cur.first][cur.second] = range;
			}
		}
		for (int i = 0; i < 4; i++) {
			int a = di[i] + cur.first;
			int b = dj[i] + cur.second;
			if (a >= 0 && b >= 0 && a < N && b < N && visited2[a][b] == 0 && dp[a][b] >= range) {
				q.push({{a, b}, {time + 1, range}});
				visited2[a][b] = range;
			}
		}
	}
	bool ans[1000][1000] = {{0}};
	priority_queue<Pos> pq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited2[i][j] > 0) {
				pq.push({{i, j}, visited2[i][j] - 1});
			}
		}
	}
	int count = 0;
	while (!pq.empty()) {
		pair<int, int> cur = pq.top().pos;
		int d = pq.top().dist;
		pq.pop();
		if (ans[cur.first][cur.second]) continue;
		ans[cur.first][cur.second] = true;
		count++;
		if (d == 0) continue;
		for (int i = 0; i < 4; i++) {
			int a = cur.first + di[i];
			int b = cur.second + dj[i];
			if (a >= 0 && b >= 0 && a < N && b < N && arr[a][b] != '#') {
				pq.push({{a, b}, d - 1});
			}
		}		
	}
	cout << count << endl;
}
