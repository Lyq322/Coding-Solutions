#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, T;
int adj[300][300];

int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) adj[i][j] = 0;
			else adj[i][j] = -1;
		}
	}
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a][b] = c;
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			if (adj[i][k] > 0) {
				for (int j = 0; j < N; j++) {
					if (adj[k][j] > 0) {
						if (adj[i][j] == -1 || adj[i][j] > max(adj[i][k], adj[k][j])) {
							adj[i][j] = max(adj[i][k], adj[k][j]);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		a--;
		b--;
		cout << adj[a][b] << endl;
	}
}

/*
Floyd-Warshall on input adj list
Check if path exists
*/