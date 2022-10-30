#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll N;
	cin >> N;
	cout << 0 << endl;
	if (N >= 2) cout << 6 << endl;
	if (N >= 3) cout << 28 << endl;
	for (ll i = 4; i <= N; i++) {
		ll t = (i * i) * (i * i - 1) / 2;
		t -= 4 * 2 / 2;
		t -= 4 * 2 * 3 / 2;
		t -= (i - 4) * 4 * 4 / 2;
		t -= 4 * 4 / 2;
		t -= (i - 2 - 2) * 4 * 6 / 2;
		t -= (i - 4) * (i - 4) * 8 / 2;
		cout << t << endl;
	}
}
