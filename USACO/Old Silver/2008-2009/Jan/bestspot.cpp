#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int nap[500];
int adj[500][500] = {{0}};

int main() {
	int T, F, B;
	cin >> T >> F >> B;
	for (int i = 0; i < F; i++) {
		cin >> nap[i];
		nap[i]--;
	}
	int a, b, c;
	for (int i = 0; i < B; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a][b] = c;
		adj[b][a] = c;
	}
	for (int k = 0; k < T; k++) {
		for (int i = 0; i < T; i++) {
			if (adj[i][k] > 0) {
				for (int j = 0; j < T; j++) {
					if (i == j) continue;
					if (adj[k][j] > 0) {
						if (adj[i][j] == 0 || adj[i][j] > adj[i][k] + adj[k][j]) {
							adj[i][j] = adj[i][k] + adj[k][j];
						}
					}
				}
			}
		}
	}
	int ans = 0;
	int t = -1;
	for (int i = 0; i < T; i++) {
		int total = 0;
		for (int j = 0; j < F; j++) {
			total += adj[i][nap[j]];
		}
		if (t == -1 || t > total) {
			t = total;
			ans = i;
		}
	}
	cout << ans + 1 << endl;
}
/*
We need to calculate the shortest path from every single node so we can do either floyd-warshall once or dijkstra multiple times
Floyd-Warshall is easier to implement
*/