#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
	ll N;
	cin >> N;
	ll arr[200000];
	for (ll i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (ll i = N; i < 2 * N; i++) {
		arr[i] = arr[i - N];
	}
	ll minimum = 1000000000;
	ll cur_index;
	int t = 0;
	for (int i = 0; i < N; i++) {
		t += arr[i];
		t--;
		if (minimum > t) {
			minimum = t;
			cur_index = i;
		}
	}
	ll cur_need = cur_index + 1;
	ll ans = 0;
	bool visited[100000] = {0};
	for (ll i = cur_index; i < N + cur_index; i++) {
		if (arr[i] == 0) {
			continue;
		}
		if (cur_need <= i) {
			cur_need = i + 1;
		}
		for (ll j = 0; j < arr[i] - 1; j++) {
			ans += (cur_need - i) * (cur_need - i);
			arr[cur_need]++;
			cur_need++;
		}
	}
	cout << ans << endl;
}	

/*
Notice that we want each cow to move as little as possible, even if that means moving more cows, since it takes d^2 energy
Also notice that we don’t want multiple cows to have the same endpoint
This means we can keep track of the cur_index (the index of the room we are currently at) and the cur_need (the lowest index of the room we still haven’t sent cows to)
	Cur_need has to be > cur_index since cows can only go clockwise
Partial sol: For each room, we loop over the cows in that room (which may or may not be the original number of cows in the input, depending on if there has been a cow that was sent to that room before). For each cow in that room, we send it to the cur_need, and increment cur_need by 1
However we cannot start at any random location — we cannot have the number of cows in the cur_index room equal 0
The problem can be solved using prefix sum, by finding the minimum ps at a random point, and using the index right after the minimum ps’s index as the starting point
*/
