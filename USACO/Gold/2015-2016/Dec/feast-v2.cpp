#include <bits/stdc++.h>
using namespace std;

ifstream fin;
ofstream fout;

int main() {
	fin.open("feast.in");
	fout.open("feast.out");
	int T, A, B;
	fin >> T >> A >> B;
	int visited[5000001][2] = {{0}};
	queue<pair<int, bool>> q;
	q.push({0, false});
	while (!q.empty()) {
		int cur = q.front().first;
		bool water = q.front().second;
		q.pop();
		if (!water) {
			if (!visited[cur / 2][1]) {
				visited[cur / 2][1] = true;
				q.push({cur / 2, 1});
			}
		}
		if (cur + A <= T && !visited[cur + A][water]) {
			visited[cur + A][water] = true;
			q.push({cur + A, water});
		}
		if (cur + B <= T && !visited[cur + B][water]) {
			visited[cur + B][water] = true;
			q.push({cur + B, water});
		}
	}
	int ans = 0;
	for (int i = 0; i <= T; i++) {
		if (visited[i][0] || visited[i][1]) ans = i;
	}
	fout << ans << endl;
}
