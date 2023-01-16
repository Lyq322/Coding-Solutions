#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
The game is the same as if the rules are the following:
	At each move, the cows first divide every pile of stone by x (can be 1), then remove 1 stone from each pile
After dividing by x, if there are an odd number of piles with y stones then whoever first takes one from those odd piles wins
This means that we don’t want any odd piles after Bessie’s first move
	So after dividing by x, the piles with y stones we take from needs to be odd, and the piles with y - 1 stones also needs to be odd (exception is when y - 1 = 0)
Using prefix sum, we can find for each # of stones y, the number of piles it will have after dividing by x
*/

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
