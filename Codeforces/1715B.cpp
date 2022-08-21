#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll T;
	cin >> T;
	while (T--) {
		ll N, K, B, S;
		cin >> N >> K >> B >> S;
		ll a = S - B * K;
		if (a < 0) {
			cout << -1 << endl;
			continue;
		}
		ll arr[100000] = {0};
		arr[0] = B * K;
		for (ll i = 0; i < N; i++) {
			if (a >= K - 1) {
				a -= K - 1;
				arr[i] += K - 1;
			}
			else {
				arr[i] += a;
				a = 0;
			}
		}
		if (a == 0) {
			for (ll i = 0; i < N; i++) {
				cout << arr[i] << ' ';
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}
