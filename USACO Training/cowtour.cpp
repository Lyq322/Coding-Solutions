#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll N;
pii cities[150];
long double adj[150][150] = {{0}};
long double max_dist[150] = {0};

long double dist(ll i, ll j) {
	long double a = (cities[i].first - cities[j].first) * (cities[i].first - cities[j].first) + (cities[i].second - cities[j].second) * (cities[i].second - cities[j].second);
	return sqrt(a);
}

int main() {
	cin >> N;
	ll a, b;
	for (ll i = 0; i < N; i++) {
		cin >> a >> b;
		cities[i] = {a, b};
	}
	char c;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> c;
			if (i == j) continue;
			if (c == '1') {
				adj[i][j] = dist(i, j);
				max_dist[i] = max(max_dist[i], dist(i, j));
				max_dist[j] = max(max_dist[j], dist(i, j));
			}
			else {
				adj[i][j] = 0;
			}
		}
	}
	for (ll k = 0; k < N; k++) {
		for (ll i = 0; i < N; i++) {
			if (adj[i][k] <= 0) continue;
			for (ll j = 0; j < N; j++) {
				if (i != j && adj[k][j] > 0 && (adj[i][j] == 0 || adj[i][j] > adj[i][k] + adj[k][j])) {
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			max_dist[i] = max(max_dist[i], adj[i][j]);
		}
	}
	bool visited[150] = {0};
	long double diameters[150] = {0};
	ll group[150] = {0};
	ll count = 0;
	for (ll i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			queue<ll> q;
			q.push(i);
			group[i] = count;
			diameters[count] = max_dist[i];
			while (!q.empty()) {
				ll cur = q.front();
				q.pop();
				for (ll j = 0; j < N; j++) {
					if (adj[cur][j] > 0 && !visited[j]) {
						q.push(j);
						visited[j] = true;
						group[j] = count;
						diameters[count] = max(diameters[count], max_dist[j]);
					}
				}
			}
			count++;
		}
	}
	long double ans = -1L;
	long double ld = -1L;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			if (group[i] == group[j]) continue;
			long double d = max_dist[i] + max_dist[j] + dist(i, j);
			if (ld < 0 || ld > dist(i, j)) {
			    ld = dist(i, j);
			}
			if (ans < 0 || ans > d) {
				ans = d;
			}
		}
	}
	for (ll i = 0; i < count; i++) {
		ans = max(ans, diameters[i]);
	}
	cout << fixed << setprecision(6) << ans << endl;
}

/*
N = 150 is pretty small, we can do N^3 with this
We can try every single pair of points to check if we can add an edge there
	We can only add if they are not in the same “group”
	BFS to check their group
	O(N^2) using adj lists
2 cases: If the total diameter of the two connected groups includes the edge we created
	The total diameter of the two connected groups = the length of the edge we created + the sum of the longest path from the two endpoints of the edge we created in their own group
	The longest path from each endpoint can be checked using dijkstra/floyd warshall, calculated separately
	O(N^3 + N^2) = O(N^3)
And if it doesn’t
	Diameter = max(all diameters)
	The diameters can be calculated at the same time as the BFS to check each point’s group and the dijkstra/floyd warshall
	O(N^3 + N) = O(N^3)
*/