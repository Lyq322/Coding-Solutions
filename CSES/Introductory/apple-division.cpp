#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll arr[20];
ll total = 0;
ll ans = 20000000000;

void solve(int pos, ll t) {
	if (pos == N) {
		ans = min(ans, abs(total - 2 * t));
		return;
	}
	solve(pos + 1, t + arr[pos]);
	solve(pos + 1, t);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	solve(0, 0);
	cout << ans << endl;
}
