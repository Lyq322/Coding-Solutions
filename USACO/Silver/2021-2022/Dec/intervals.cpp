#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, M;
pair<ll, ll> llervals[200000];
ll startP[5001] = {0};
ll endP[5001] = {0};
ll ans[10010] = {0};

int main() {
	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		cin >> llervals[i].first >> llervals[i].second;
	}
	for (ll i = 0; i < N; i++) {
		startP[llervals[i].first]++;
		endP[llervals[i].second]++;
	}
	for (ll i = 0; i <= M; i++) {
		for (ll j = 0; j <= M; j++) {
			if (startP[i] != 0 && startP[j] != 0) {
				ll t = startP[i] * startP[j];
				ans[i + j] += t;
			}
		}
	}
	for (ll i = 0; i <= M; i++) {
		for (ll j = 0; j <= M; j++) {
			if (endP[i] != 0 && endP[j] != 0) {
				ll t = endP[i] * endP[j];
				ans[i + j + 1] -= t;
			}
		}
	}
	ll t = 0;
	for (ll i = 0; i <= 2 * M; i++) {
		t += ans[i];
		cout << t << endl;
	}
}
