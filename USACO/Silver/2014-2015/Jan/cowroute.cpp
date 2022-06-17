#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct City {
	ll pos;
	ll dist;
	ll edge;
};

pair<ll, ll> adj[1000][1000];

bool operator<(City a, City b) {
	return a.dist > b.dist;
}

int main() {
	ll A, B, N;
	cin >> A >> B >> N;
	A--;
	B--;
	for (ll i = 0; i < 1000; i++) {
		for (ll j = 0; j < 1000; j++) {
			adj[i][j] = {0, 0};
		}
	}
	ll C, M;
	for (ll i = 0; i < N; i++) {
		cin >> C >> M;
		ll a;
		ll arr[100] = {0};
		for (ll j = 0; j < M; j++) {
			cin >> arr[j];
			arr[j]--;
		}
		for (ll j = 0; j < M - 1; j++) {
			for (ll k = j + 1; k < M; k++) {
				if (j != k) {
					if (adj[arr[j]][arr[k]].first == 0 || adj[arr[j]][arr[k]].first > C) {
						adj[arr[j]][arr[k]].first = C;
						adj[arr[j]][arr[k]].second = k - j;
					}
				}
			}
		}
	}
	priority_queue<City> q;
	q.push({A, 0});
	ll distance[1000] = {0};
	bool visited[1000] = {0};
	ll edges[1000] = {0};
	for (ll i = 0; i < 1000; i++) {
		distance[i] = -1;
		edges[i] = -1;
	}
	edges[A] = 0;
	distance[A] = 0;
	while (!q.empty()) {
		ll cur_pos = q.top().pos;
		ll cur_dist = q.top().dist;
		ll cur_edge = q.top().edge;
		q.pop();
		if (visited[cur_pos]) {
			if (cur_dist == distance[cur_pos]) {
				if (edges[cur_pos] == -1 || edges[cur_pos] > cur_edge) {
					edges[cur_pos] = cur_edge;
				}
			}
			continue;
		}
		if (edges[cur_pos] == -1 || edges[cur_pos] > cur_edge) {
			edges[cur_pos] = cur_edge;
		}
		visited[cur_pos] = true;
		for (ll i = 0; i < 1000; i++) {
			if (adj[cur_pos][i].first == 0) continue;
			ll next_pos = i;
			ll d = adj[cur_pos][i].first;
			ll e = adj[cur_pos][i].second;
			if (!visited[next_pos] && (distance[next_pos] == -1 || distance[next_pos] > distance[cur_pos] + d)) {
				distance[next_pos] = distance[cur_pos] + d;
				q.push({next_pos, distance[next_pos], cur_edge + e});
			}
		}
	}
	cout << distance[B] << ' ';
	cout << edges[B] << endl;
}

/*
Make paths between all pairs of cities in a route
Use dijkstra’s to find shortest path between A to B
Test case 8/12
*/