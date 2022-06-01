#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
int adj[100][100];

int main() {
	cin >> N >> M;
	int a;
	for (int i = 0; i < M; i++) {
		cin >> a;
		a--;
		v.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)  {
			cin >> adj[i][j];
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < M - 1; i++) {
		ans += adj[v[i]][v[i + 1]];
	}
	cout << ans << endl;
}
/*
Floyd-Warshall on input adj list
Does not need to check if path exists because all pairs are connected, even if the weight of an edge is 0
*/