#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll N, M;
	cin >> N >> M;
	ll arr[100000];
	for (ll i = 0; i < N; i++) {
		cin >> arr[i];
	}
	ll a, b;
	ll ans = 0;
	for (ll i = 0; i < N; i++) {
		ans += (i + 1) * (N - i);
	}
	for (ll i = 1; i < N; i++) {
		if (arr[i] == arr[i - 1]) {
			ans -= i * (N - i);
		}
	}
	for (ll  i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		if (N == 1) {
			cout << 1 << endl;
			continue;
		}
		if (a != 0 && a != N - 1) {
			if (arr[a - 1] != arr[a] && arr[a - 1] == b) {
				ans -= a * (N - a);
			}
			if (arr[a + 1] != arr[a] && arr[a + 1] == b) {
				ans -= (a + 1) * (N - a - 1);
			}
			if (arr[a - 1] == arr[a] && arr[a - 1] != b) {
				ans += a * (N - a);
			}
			if (arr[a + 1] == arr[a] && arr[a + 1] != b) {
				ans += (a + 1) * (N - a - 1);
			}
		}
		else if (a == 0) {
			if (arr[a + 1] != arr[a] && arr[a + 1] == b) {
				ans -= (a + 1) * (N - a - 1);
			}
			if (arr[a + 1] == arr[a] && arr[a + 1] != b) {
				ans += (a + 1) * (N - a - 1);
			}
		}
		else if (a == N - 1) {
			if (arr[a - 1] != arr[a] && arr[a - 1] == b) {
				ans -= a * (N - a);
			}
			if (arr[a - 1] == arr[a] && arr[a - 1] != b) {
				ans += a * (N - a);
			}
		}
		cout << ans << endl;
		arr[a] = b;
	}
}
