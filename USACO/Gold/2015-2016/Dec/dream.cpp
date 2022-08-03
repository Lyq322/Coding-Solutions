#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Loc {
	pii pos;
	bool orange;
	bool slide;
	int dir;
	int moves;
};

/*
0 - right
1 - down
2 - left
3 - up
*/

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main() {
	int N, M;
	cin >> N >> M;
	int arr[1000][1000];
	// 0 = red
	// 1 = pink
	// 2 = orange
	// 3 = blue
	// 4 = purple
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int visited[1000][1000][4][2] = {{{{0}}}};
	queue<Loc> q;
	q.push({{0, 0}, false, false, 0, 0});
	visited[0][0][0][0] = 1;
	bool found = false;
	while (!q.empty()) {
		pii pos = q.front().pos;
		bool o = q.front().orange;
		bool s = q.front().slide;
		int d = q.front().dir;
		int m = q.front().moves;
		//cout << pos.first << ' ' << pos.second << ' ' << m << endl;
		if (pos.first == N - 1 && pos.second == M - 1) {
			found = true;
			cout << m << endl;
			break;
		}
		q.pop();
		if (s == true) {
			int a = pos.first + di[d];
			int b = pos.second + dj[d];
			if (a >= 0 && b >= 0 && a < N && b < M) {
				if (visited[a][b][d][0] == 0 && arr[a][b] == 4) {
					visited[a][b][d][0] = 1;
					q.push({{a, b}, false, true, d, m + 1});
				}
				else if (arr[a][b] == 0 || arr[a][b] == 3) {
					for (int i = 0; i < 4; i++) {
						a = pos.first + di[i];
						b = pos.second + dj[i];
						if (a >= 0 && b >= 0 && a < N && b < M && arr[a][b] != 0 && arr[a][b] != 3) {
							if (visited[a][b][0][1] == 0 && arr[a][b] == 2) {
								visited[a][b][0][1] = 1;
								q.push({{a, b}, true, false, d, m + 1});
							}
							else if (visited[a][b][i][0] == 0 && arr[a][b] == 4) {
								visited[a][b][0][0] = 1;
								q.push({{a, b}, false, true, i, m + 1});
							}
							else if (visited[a][b][0][0] == 0 && arr[a][b] == 1) {
								visited[a][b][0][0] = 1;
								q.push({{a, b}, false, false, d, m + 1});
							}
						}
					}
				}
				else if (visited[a][b][0][0] == 0 && arr[a][b] == 1) {
					visited[a][b][0][0] = 1;
					q.push({{a, b}, false, false, d, m + 1});
				}
				else if (visited[a][b][0][1] == 0 && arr[a][b] == 2) {
					visited[a][b][0][1] = 1;
					q.push({{a, b}, true, false, d, m + 1});
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				int a = pos.first + di[i];
				int b = pos.second + dj[i];
				if (a >= 0 && b >= 0 && a < N && b < M) {
					if (visited[a][b][0][o] == 0 && (arr[a][b] == 1 || (arr[a][b] == 3 && o == true))) {
						visited[a][b][0][o] = 1;
						q.push({{a, b}, o, s, d, m + 1});
					}
					else if (visited[a][b][0][1] == 0 && arr[a][b] == 2) {
						visited[a][b][0][1] = 1;
						q.push({{a, b}, true, s, d, m + 1});
					}
					else if (visited[a][b][i][0] == 0 && arr[a][b] == 4) {
						visited[a][b][i][0] = 1;
						q.push({{a, b}, false, true, i, m + 1});
					}
				}
			}
		}
	}
	if (!found) cout << -1 << endl;
}

/*
BFS question with some more requirements
In addition to the position, we also need to track if we have the orange smell (bool), if we are currently sliding (bool), and what direction we are sliding in (int 0-3)
Notice that in the visited array, we also need to keep track of the sliding direction and if we have the orange smell (eg. we might need to visit a position twice because we needed to get the orange smell first)
Sadly 14/16 :(
*/