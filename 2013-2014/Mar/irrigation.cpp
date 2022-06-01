#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

vector<pii> cities;
ll N, C;
bool visited[2000] = {0};
ll dist[2000] = {0};
ll adj[2000][2000];

ll find_dist(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	cin >> N >> C;
	ll a, b;
	for (ll i = 0; i < N; i++) {
		cin >> a >> b;
		cities.push_back({a, b});
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			adj[i][j] = -1;
		}
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			if (i == j) continue;
			ll dist_btw = find_dist(cities[i], cities[j]);
			if (dist_btw >= C) {
				adj[i][j] = dist_btw;
				adj[j][i] = dist_btw;
			}
		}
	}
	for (ll i = 1; i < N; i++) {
		dist[i] = -1;
	}
	ll cur = 0;
	while (cur != -1) {
		for (ll i = 0; i < N; i++) {
			if (visited[i] || adj[cur][i] == -1 || i == cur) continue;
			if (dist[i] == -1 || dist[i] > adj[cur][i]) {
				dist[i] = adj[cur][i];
			}
		}
		visited[cur] = true;
		cur = -1;
		ll minimum = -1;
		for (ll i = 0; i < N; i++) {
			if (visited[i] || i == cur || dist[i] == -1) continue;
			if (minimum == -1 || minimum > dist[i]) {
				minimum = dist[i];
				cur = i;
			}
		}
	}
	bool connected = true;
	ll ans = 0;
	for (ll i = 0; i < N; i++) {
		if (dist[i] == -1) {
			connected = false;
			cout << -1 << endl;
			break;
		}
		ans += dist[i];
	}
	if (connected) cout << ans << endl;
}

/*
Calculate distance between every pair of cities
	Only record the edges with length >= C in the adj
	MST
	Check if all connected
		True -> ans
		False -> -1
*/