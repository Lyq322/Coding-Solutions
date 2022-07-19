#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll T;
	cin >> T;
	for (ll z = 0; z < T; z++) {
		ll N;
		ll arr[100000];
		cin >> N;
		for (ll i = 0; i < N; i++) {
			cin >> arr[i];
		}
		if (N % 2 == 1) {
			ll ans = 0;
			for (ll i = 1; i < N; i = i + 2) {
				if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) continue;
				ans += max(arr[i - 1] + 1, arr[i + 1] + 1) - arr[i];
			}
			cout << ans << endl;
		}
		else {
			ll ans = 0;
			vector<ll> left_even;
			vector<ll> right_even;
			vector<ll> left_odd;
			vector<ll> right_odd;
			left_even.push_back(0);
			left_odd.push_back(0);
			right_even.push_back(0);
			right_odd.push_back(0);
			for (ll i = 2; i < N - 1; i = i + 2) {
				if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
					left_even.push_back(ans);
					continue;
				}
				ans += max(arr[i - 1] + 1, arr[i + 1] + 1) - arr[i];
				left_even.push_back(ans);
			}
			ans = 0;
			for (ll i = N - 2; i >= 2; i = i - 2) {
				if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
					right_even.push_back(ans);
					continue;
				}
				ans += max(arr[i - 1] + 1, arr[i + 1] + 1) - arr[i];
				right_even.push_back(ans);
			}
			ans = 0;
			for (ll i = 1; i < N - 1; i = i + 2) {
				if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
					left_odd.push_back(ans);
					continue;
				}
				ans += max(arr[i - 1] + 1, arr[i + 1] + 1) - arr[i];
				left_odd.push_back(ans);
			}
			ans = 0;
			for (ll i = N - 3; i >= 1; i = i - 2) {
				if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
					right_odd.push_back(ans);
					continue;
				}
				ans += max(arr[i - 1] + 1, arr[i + 1] + 1) - arr[i];
				right_odd.push_back(ans);
			}
			ans = -1;
			for (ll i = 0; i < left_odd.size(); i++) {
				ll a = left_odd[i] + right_odd[left_odd.size() - i - 1];
				ll b = left_odd[i] + right_even[left_odd.size() - i - 1];
				ll d = left_even[i] + right_even[left_odd.size() - i - 1];
				if (ans == -1 || ans > a) {
					ans = a;
				}
				if (ans == -1 || ans > b) {
					ans = b;
				}
				if (ans == -1 || ans > d) {
					ans = d;
				}
			}
			cout << ans << endl;
		}
	}
}
