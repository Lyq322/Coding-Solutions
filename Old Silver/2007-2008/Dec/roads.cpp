#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll N, M;
vector<pii> fields;
ll adj[1000][1000] = {{0}};
bool visited[1000] = {0};
ll distance1[1000] = {0};

ll dist(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	cin >> N >> M;
	ll a, b;
	for (ll i = 0; i < N; i++) {
		cin >> a >> b;
		fields.push_back({a, b});
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			adj[i][j] = dist(fields[i], fields[j]);
		}
	}
	for (ll i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a][b] = 0;
		adj[b][a] = 0;
	}
	for (ll i = 1; i < N; i++) {
		distance1[i] = -1;
	}
	ll cur = 0;
	while (cur != -1) {
		for (ll i = 0; i < N; i++) {
			if (i == cur) continue;
			ll next = adj[cur][i];
			if (!visited[i] && (distance1[i] == -1 || next < distance1[i])) {
				distance1[i] = next;
			}
		}
		visited[cur] = true;
		cur = -1;
		ll minimum = -1;
		for (ll i = 0; i < N; i++) {
			if (i == cur) continue;
			if (!visited[i] && distance1[i] != -1 && (minimum == -1 || minimum > distance1[i])) {
				minimum = distance1[i];
				cur = i;
			}
		}
	}
	ll ans2 = 0;
	long double ans = 0L;
	for (ll i = 0; i < N; i++) {
		ans += sqrt(distance1[i]);
		ans2 += (ll) sqrt(distance1[i]);
	}
	cout << fixed << setprecision(2) << ans << endl;
}

/*
Key Observation
	Set the distance between farms that are already connected to 0
Pseudocode
	Set the distance between farms that are already connected to 0
	Set everything else to the distance ^ 2 to avoid doubles
	MST
	Print using cout << fixed << setprecision(2) << ans << endl;
*/