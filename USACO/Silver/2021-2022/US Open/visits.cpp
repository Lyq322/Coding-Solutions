#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll N;
map<ll, pii> cows;
bool visited[100000] = {0};

ll find_min(ll p) {
	ll minimum = -1;
	bool visited2[100000] = {0};
	visited2[p] = true;
	while (true) {
		if (minimum == -1 || minimum > cows[p].second) {
			minimum = cows[p].second;
		}
		if (!visited2[cows[p].first]) {
			visited2[cows[p].first] = true;
			p = cows[p].first;
		}
		else {
			break;
		}
	}
	return minimum;
}

int main() {
	cin >> N;
	ll a, v;
	for (ll i = 0; i < N; i++) {
		cin >> a >> v;
		cows[i] = {a - 1, v};
	}
	ll ans = 0;
	for (ll i = 0; i < N; i++) {
		if (!visited[i]) {
			ll minimum = -1;
			ll t = 0;
			ll pos = i;
			visited[i] = true;
			set<ll> been;
			been.insert(i);
			while (true) {
				ll next = cows[pos].first;
				if (minimum == -1 || minimum > cows[pos].second) {
					minimum = cows[pos].second;
				}
				t += cows[pos].second;
				if (been.find(next) != been.end()) {
					ll m = find_min(next);
					ans += t - m;
					break;
				}
				else if (visited[next]) {
					ans += t;
					break;
				}
				else {
					been.insert(next);
					visited[next] = true;
					pos = next;
				}
			}
		}
	}
	cout << ans << endl;
}
