#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll N, M;
pii food[100000];
ll spiciness[100000];

bool check(ll s) {
	ll t = 0;
	ll l = 0;
	ll r = 0;
	while (l < N && r < N) {
		if (food[r].second > s) {
			l = r + 1;
			r++;
			t = 0;
		}
		else {
			t += food[r].first;
			r++;
		}
		if (t >= M) return true;
	}
	return false;
}

int main() {
	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		cin >> food[i].first >> food[i].second;
		spiciness[i] = food[i].second;
	}
	sort(spiciness, spiciness + N);
	ll l = 0;
	ll r = N;
	ll m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (check(spiciness[m]) && (m == 0 || !check(spiciness[m - 1]))) {
			cout << spiciness[m] << endl;
			break;
		}
		else if (check(spiciness[m])) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
}

// Binary search + sliding window