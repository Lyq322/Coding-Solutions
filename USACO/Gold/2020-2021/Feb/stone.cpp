#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;
	ll arr[100000];
	ll ps[3000001] = {0};
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		ps[arr[i]]++;
	}
	sort(arr, arr + N);
	for (int i = 1; i < 3000001; i++) {
		ps[i] += ps[i - 1];
	}
	ll ans = 0;
	for (ll i = 1; i <= arr[N - 1]; i++) {
		// [i * j, i * j + i)
		ll j = 1;
		int odd_index = -1;
		int odd_index2 = -1;
		int odd_count = 0;
		while (i * j <= arr[N - 1]) {
			if ((ps[i * j + i - 1] - ps[i * j - 1]) % 2 == 1) {
				odd_count++;
				if (odd_index == -1) {
					odd_index = j;
				}
				else {
					odd_index2 = j;
				}
			}
			j++;
		}
		if (odd_count == 1 && odd_index == 1) {
			ans += ps[odd_index * i + i - 1] - ps[i * odd_index - 1];
			continue;
		}
		if (odd_count != 2) continue;
		if (odd_index != odd_index2 - 1) continue;
		ans += ps[i * odd_index2 + i - 1] - ps[i * odd_index2 - 1];
	}
	cout << ans << endl;
}
