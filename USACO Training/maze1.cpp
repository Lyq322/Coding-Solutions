#include <bits/stdc++.h>

// 2 BFS, one from each exit

using namespace std;
typedef pair<int, int> pii;

int W, H;
bool grid[201][77] = {{0}};
int moves1[201][77] = {{0}};
int moves2[201][77] = {{0}};
vector<pii> exits;
int di[8] = {0, 2, 0, -2, 0, 1, 0, -1};
int dj[8] = {2, 0, -2, 0, 1, 0, -1, 0};

int main() {
	cin >> W >> H;
	cin.ignore();
	string s;
	for (int i = 0; i < 2*H + 1; i++) {
		getline(cin, s);
		for (int j = 0; j < 2*W + 1; j++) {
			char c = s.at(j);
			if (c != ' ') {
				grid[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 2*H+1; i++) {
		if (!grid[i][0]) {
			exits.push_back({i, -1});
		}
		if (!grid[i][2*W]) {
			exits.push_back({i, 2*W + 1});
		}
	}
	for (int i = 0; i < 2*W + 1; i++) {
		if (!grid[0][i]) {
			exits.push_back({-1, i});
		}
		if (!grid[2*H][i]) {
			exits.push_back({2*H + 1, i});
		}
	}
	queue<pair<pii, int>> q;
	q.push({exits[0], 0});
	while (!q.empty()) {
		pii pos = q.front().first;
		int m = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int a = di[i] + pos.first;
			int b = dj[i] + pos.second;
			int c = di[i + 4] + pos.first;
			int d = dj[i + 4] + pos.second;
			if (a >= 0 && b >= 0 && a < 2 * H + 1 && b < 2 * W + 1 && moves1[a][b] == 0 && grid[a][b] == 0 && grid[c][d] == 0) {
				moves1[a][b] = m + 1;
				q.push({{a, b}, m + 1});
			}
		}
	}
	q.push({exits[1], 0});
	while (!q.empty()) {
		pii pos = q.front().first;
		int m = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int a = di[i] + pos.first;
			int b = dj[i] + pos.second;
			int c = di[i + 4] + pos.first;
			int d = dj[i + 4] + pos.second;
			if (a >= 0 && b >= 0 && a < 2 * H + 1 && b < 2 * W + 1 && moves2[a][b] == 0 && grid[a][b] == 0 && grid[c][d] == 0) {
				moves2[a][b] = m + 1;
				q.push({{a, b}, m + 1});
			}
		}
	}
	int maximum = 0;
	for (int i = 0; i < 2*H + 1; i++) {
		for (int j = 0; j < 2*W + 1; j++) {
			maximum = max(maximum, min(moves1[i][j], moves2[i][j]));
		}
	}
	cout << maximum << endl;
}

