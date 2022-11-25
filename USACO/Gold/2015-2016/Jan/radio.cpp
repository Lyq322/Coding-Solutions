#include <bits/stdc++.h>
using namespace std;

/*
Define dp[i][j] as the minimum energy used when farmer john is at the ith position and bessie is at the jth position
We can therefore find dp[i][j] using dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]
*/

ifstream fin;
ofstream fout;

map<char, pair<int, int>> m = {{'N', {0, 1}}, {'S', {0, -1}}, {'W', {-1, 0}}, {'E', {1, 0}}};
pair<int, int> f_pos[1001];
pair<int, int> b_pos[1001];

int dist(int i, int j) {
	return (f_pos[i].first - b_pos[j].first) * (f_pos[i].first - b_pos[j].first) + (f_pos[i].second - b_pos[j].second) * (f_pos[i].second - b_pos[j].second);
}

int main() {
	fin.open("radio.in");
	fout.open("radio.out");
	int N, M;
	fin >> N >> M;
	int bx, by, fx, fy;
	fin >> fx >> fy >> bx >> by;
	string f_path, b_path;
	fin >> f_path >> b_path;
	int dp[1001][1001];
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = 1000000000;
		}
	}
	dp[0][0] = 0;

	f_pos[0] = {fx, fy};
	b_pos[0] = {bx, by};
	for (int i = 0; i < N; i++) {
		f_pos[i + 1].first = f_pos[i].first + m[f_path[i]].first;
		f_pos[i + 1].second = f_pos[i].second + m[f_path[i]].second;
	}
	for (int i = 0; i < M; i++) {
		b_pos[i + 1].first = b_pos[i].first + m[b_path[i]].first;
		b_pos[i + 1].second = b_pos[i].second + m[b_path[i]].second;
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i == 0 && j == 0) continue;
			if (j != 0) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + dist(i, j));
			}
			if (i != 0) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist(i, j));
			}
			if (i != 0 && j != 0) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + dist(i, j));
			}
		}
	}
	fout << dp[N][M] << endl;
}
