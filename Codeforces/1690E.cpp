#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, N, K;

int main() {
	cin >> T;
	for (ll z = 0; z < T; z++) {
		cin >> N >> K;
		vector<ll> v;
		vector<ll> mod;
		ll remainder[1000] = {0};
		ll a;
		ll ans = 0;
		for (ll i = 0; i < N; i++) {
			cin >> a;
			v.push_back(a);
			remainder[a % K]++;
			ans += a / K;
		}
		if (K % 2 == 1) {
			for (ll i = 1; i <= K / 2; i++) {
				if (remainder[i] < remainder[K - i]) {
					ans += remainder[i];
					remainder[K - i] -= remainder[i];
					remainder[i] = 0;
				}
				else if (remainder[i] > remainder[K - i]) {
					ans += remainder[K - i];
					remainder[i] -= remainder[K - i];
					remainder[K - i] = 0;
				}
				else {
					ans += remainder[i];
					remainder[i] = 0;
					remainder[K - i] = 0;
				}
			}
		}
		else {
			for (ll i = 1; i < K / 2; i++) {
				if (remainder[i] < remainder[K - i]) {
					ans += remainder[i];
					remainder[K - i] -= remainder[i];
					remainder[i] = 0;
				}
				else if (remainder[i] > remainder[K - i]) {
					ans += remainder[K - i];
					remainder[i] -= remainder[K - i];
					remainder[K - i] = 0;
				}
				else {
					ans += remainder[i];
					remainder[i] = 0;
					remainder[K - i] = 0;
				}
			}
			ans += remainder[K / 2] / 2;
			remainder[K / 2] = remainder[K / 2] % 2;
		}
		for (ll i = K - 1; i > 0; i--) {
			for (ll j = 0; j < remainder[i]; j++) {
				mod.push_back(i);
			}
		}
		if (mod.size() <= 1) {
			cout << ans << endl;
			continue;
		}
		ll j = 0;
		ll i = mod.size() - 1;
		while (i > j) {
			if (mod[i] + mod[j] > K) {
				ans++;
				i--;
				j++;
			}
			else if (mod[i] + mod[j] < K) {
				i--;
			}
		}
		cout << ans << endl;
	}
}
