#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// MST
// Timed out on last case :(

struct Node {
	int weight;
	int row;
	int col;
};

bool operator<(Node a, Node b) {
	return a.weight > b.weight;
}

int main() {
	ifstream fin("fencedin.in");
	ofstream fout("fencedin.out");
	int A, B, N, M;
	fin >> A >> B >> N >> M;
	int hor[2002];
	int vert[2002];
	for (int i = 0; i < N; i++) {
		fin >> hor[i + 2];
	}
	for (int i = 0; i < M; i++) {
		fin >> vert[i + 2];
	}
	hor[0] = 0;
	hor[1] = A;
	vert[0] = 0;
	vert[1] = B;
	sort(hor, hor + N + 2);
	sort(vert, vert + M + 2);
	int hor_edges[2001];
	int vert_edges[2001];
	for (int i = 0; i < N + 1; i++) {
		vert_edges[i] = hor[i + 1] - hor[i];
	}
	for (int i = 0; i < M + 1; i++) {
		hor_edges[i] = vert[i + 1] - vert[i];
	}
	priority_queue<Node> q;
	q.push({0, 0, 0});
	ll dist[2001][2001];
	for (int i = 0; i < M + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			dist[i][j] = -1;
		}
	}
	bool visited[2001][2001] = {{0}};
	dist[0][0] = 0;
	while (!q.empty()) {
		int w = q.top().weight;
		int r = q.top().row;
		int c = q.top().col;
		q.pop();
		if (visited[r][c]) {
			continue;
		}
		visited[r][c] = true;
		int new_r, new_c, next_w;
		// up 
		if (r > 0) {
			new_r = r - 1;
			new_c = c;
			next_w = vert_edges[c];
			if (!visited[new_r][new_c] && (dist[new_r][new_c] == -1 || dist[new_r][new_c] > next_w)) {
				dist[new_r][new_c] = next_w;
				q.push({next_w, new_r, new_c});
			}
		}
		// down
		if (r < M) {
			new_r = r + 1;
			new_c = c;
			next_w = vert_edges[c];
			if (!visited[new_r][new_c] && (dist[new_r][new_c] == -1 || dist[new_r][new_c] > next_w)) {
				dist[new_r][new_c] = next_w;
				q.push({next_w, new_r, new_c});
			}
		}
		// left
		if (c > 0) {
			new_r = r;
			new_c = c - 1;
			next_w = hor_edges[r];
			if (!visited[new_r][new_c] && (dist[new_r][new_c] == -1 || dist[new_r][new_c] > next_w)) {
				dist[new_r][new_c] = next_w;
				q.push({next_w, new_r, new_c});
			}
		}
		// right
		if (c < N) {
			new_r = r;
			new_c = c + 1;
			next_w = hor_edges[r];
			if (!visited[new_r][new_c] && (dist[new_r][new_c] == -1 || dist[new_r][new_c] > next_w)) {
				dist[new_r][new_c] = next_w;
				q.push({next_w, new_r, new_c});
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < M + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			ans += dist[i][j];
		}
	}
	fout << ans << endl;
}
