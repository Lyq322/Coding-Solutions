#include <bits/stdc++.h>
using namespace std;

/*
We know that the final order of the fields Bessie eats is going to be ordered by the quality of the grass
This means we should first sort the fields by their quality
We can use a dp array to find the maximum energy stopping at field i
*/

int N, M;
int dist[1000][1000] = {{0}};
vector<pair<pair<int, int>, vector<int>>> grass;

bool comp(pair<pair<int, int>, vector<int>> a, pair<pair<int, int>, vector<int>> b) {
	return a.first.first < b.first.first;
}

void find_dist() {
	for (int i = 0; i < N; i++) {
		bool visited[1000] = {0};
		queue<pair<int, int>> q;
		q.push({i, 0});
		visited[i] = true;
		while (!q.empty()) {
			int pos = q.front().first;
			int d = q.front().second;
			q.pop();
			for (int j = 0; j < grass[pos].second.size(); j++) {
				int next = grass[pos].second[j];
				if (!visited[next]) {
					visited[next] = true;
					q.push({next, d + M});
					dist[i][next] = d + M;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int a, b;
	// pair<pair<quality, original_index>, adj_vector>>
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vector<int> v;
		int c;
		for (int j = 0; j < b; j++) {
			cin >> c;
			v.push_back(c - 1);
		}
		grass.push_back({{a, i}, v});
	}
	sort(grass.begin(), grass.end(), comp);
	// convert adj list into new indices
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		m[grass[i].first.second] = i;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < grass[i].second.size(); j++) {
			grass[i].second[j] = m[grass[i].second[j]];
		}
	}
	// find dist between all pairs of fields
	find_dist();
	// dp[i] defined as the maximum grass when stopping at field i
	int dp[1001] = {0};
	dp[0] = grass[0].first.first;
	int ans = dp[0];
	for (int i = 1; i < N; i++) {
		dp[i] = grass[i].first.first;
		for (int j = 0; j < i; j++) {
			if (dist[j][i] == 0) continue;
			int t = dp[j] - dist[j][i] + grass[i].first.first;
			dp[i] = max(dp[i], t);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
