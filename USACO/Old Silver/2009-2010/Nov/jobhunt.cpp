#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int from;
	int to;
	int weight;
};

int main() {
	int D, P, C, S, F;
	cin >> D >> P >> C >> F >> S;
	int a, b, c;
	Edge edges[500];
	for (int i = 0; i < P; i++) {
		cin >> a >> b;
		a--;
		b--;
		edges[i] = {a, b, 0 - D};
	}
	for (int i = 0; i < F; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		c -= D;
		edges[i + P] = {a, b, c};
	}
	int T = P + F;
	int dist[220];
	for (int i = 0; i < C; i++) {
		dist[i] = 1000000000;
	}
	S--;
	dist[S] = 0 - D;
	bool loop = false;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < T; j++) {
			if (dist[edges[j].to] > dist[edges[j].from] + edges[j].weight) {
				if (i == C - 1) {
					loop = true;
					cout << -1 << endl;
					break;
				}
				dist[edges[j].to] = dist[edges[j].from] + edges[j].weight;
			}
		}
		if (loop) break;
	}
	if (!loop) {
		int ans = 1000000000;
		for (int i = 0; i < C; i++) {
			ans = min(ans, dist[i]);
		}
		cout << 0 - ans << endl;
	}
}

/*
Earning D money per city is the same as adding $D to every edge
There can be negative edges, so we cannot use Dijkstra’s
However, we can use Bellman Ford since V, E are small
Also very easy to check for cycles using Bellman Ford
*/