#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;
vector<vector<int>> adj;
bool visited[100];
int dist[100] = {0};
int parent[100];
int inf = 100001;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	int a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			adj[i].push_back(a);
		}
	}
	for (int i = 1; i < N; i++) {
		dist[i] = inf;
	}
	int current = 0;
	while (current != -1) {
		for (int i = 0; i < N; i++) {
			int next = adj[current][i];
			if (!visited[i] && next != 0) {
				if (next < dist[i]) {
					dist[i] = next;
					parent[i] = current;
				}
			}
		}
		visited[current] = true;
		current = -1;
		int minimum = -1;
		for (int i = 0; i < N; i++) {
			if (!visited[i] && dist[i] != 100001 && (minimum == -1 || dist[i] < minimum)) {
				minimum = dist[i];
				current = i;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += dist[i];
	}
	cout << ans << endl;
}

/*
Solution
	Straightforward MST
	Pseudocode
		Same as Dijkstra except when updating and going to the next node, use the minimum edge length instead of the minimum length from the source
*/