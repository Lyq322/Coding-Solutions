#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<vector<pii>> adj;
int dist[100] = {0};
bool visited[100] = {0};
int parent[100] = {0};

int dijkstra() {
    int dist1[100] = {0};
    bool visited1[100] = {0};
    for (int i = 1; i < N; i++) {
        dist1[i] = -1;
    }
    int current = 0;
    while (current != -1) {
        for (int i = 0; i < adj[current].size(); i++) {
            int next = adj[current][i].first;
            if (!visited1[next]) {
                if (dist1[next] == -1 || dist1[next] > dist1[current] + adj[current][i].second) {
                    dist1[next] = dist1[current] + adj[current][i].second;
                } 
            }
        }
        visited1[current] = true;
        current = -1;
        int minimum = -1;
        for (int i = 0; i < N; i++) {
            if (!visited1[i]) {
                if (dist1[i] != -1 && (minimum == -1 || minimum > dist1[i])) {
                    minimum = dist1[i]; 
                    current = i;
                }
            }
        }
    } 
    return dist1[N - 1];
}

int main() {
	cin >> N >> M;
    for (int i = 0; i < N; i++) {
        adj.push_back({});
    }
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 1; i < N; i++) {
        dist[i] = -1;
    }
    int current = 0;
    while (current != -1) {
        for (int i = 0; i < adj[current].size(); i++) {
            int next = adj[current][i].first;
            if (!visited[next]) {
                if (dist[next] == -1 || dist[next] > dist[current] + adj[current][i].second) {
                    dist[next] = dist[current] + adj[current][i].second;
                    parent[next] = current;
                } 
            }
        }
        visited[current] = true;
        current = -1;
        int minimum = -1;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                if (dist[i] != -1 && (minimum == -1 || minimum > dist[i])) {
                    minimum = dist[i]; 
                    current = i;
                }
            }
        }
    } 
    current = N - 1;
    int ans = 0;
    while (current != 0) {
        int previous = parent[current];
        int index1, index2;
        for (int i = 0; i < adj[previous].size(); i++) {
            if (adj[previous][i].first == current) {
                index1 = i;
                adj[previous][i].second *= 2;
            }
        }
        for (int i = 0; i < adj[current].size(); i++) {
            if (adj[current][i].first == previous) {
                index2 = i;
                adj[current][i].second *= 2;
            }
        }
        ans = max(ans, dijkstra());
        adj[previous][index1].second /= 2;
        adj[current][index2].second /= 2;
        current = previous;
    }
    cout << ans - dist[N - 1] << endl;
}

/*
Key Observation
	N = 100, M = 10000 -> too slow to check every single connection and use dijkstra
	Only need to check some connections: the connections that are used in the original path. That is, if the original path from 0 to N - 1 does not use the connection, then there is no need to check it. 
Pseudocode
	Dijkstra
	Current = N - 1
	Ans = 0;
	While current is not the start/0
		Previous = parent[current]
		Change the distance between previous and current, both ways
			Adj[previous][i].second and adj[current][i].second
		Dijkstra, return dist[N - 1]
		Ans = max(ans, dijkstra)
*/