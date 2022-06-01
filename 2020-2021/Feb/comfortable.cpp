#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> cows;
bool grid[2500][2500];
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main() {
	int a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cows.push_back({a + 550, b + 550});
	}
	int total = 0;
	for (int i = 0; i < N; i++) {
		if (grid[cows[i].first][cows[i].second]) {
			cout << total - i - 1 << endl;
		}
		else {
			total++;
			queue<pii> q;
			q.push(cows[i]);
			grid[cows[i].first][cows[i].second] = true;
			for (int j = 0; j < 4; j++) {
				if (grid[cows[i].first + di[j]][cows[i].second + dj[j]]) {
					q.push({cows[i].first + di[j], cows[i].second + dj[j]});
				}
			}
			while (!q.empty()) {
				pii pos = q.front();
				q.pop();
				int adj = 0;
				int p;
				for (int j = 0; j < 4; j++) {
					if (grid[pos.first + di[j]][pos.second + dj[j]]) {
						adj++;
					}
					else {
						p = j;
					}
				}
				if (adj == 3) {
					int new_x = pos.first + di[p];
					int new_y = pos.second + dj[p];
					grid[new_x][new_y] = true;
					total++;
					q.push({new_x, new_y});
					for (int j = 0; j < 4; j++) {
						if (grid[new_x + di[j]][new_y + dj[j]]) {
							q.push({new_x + di[j], new_y + dj[j]});
						}
					}
				}
			}
			cout << total - i - 1 << endl;
		}
	}
}
